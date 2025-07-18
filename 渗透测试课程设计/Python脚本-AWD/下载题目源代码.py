import paramiko
import os
import stat
import threading
from tqdm import tqdm  # 进度条支持（可选）

# ====== 配置区域 ======
SERVERS = [
    {"host": "172.16.20.231", "user": "elab"},
    {"host": "172.16.20.8", "user": "elab"},
    {"host": "172.16.20.168", "user": "elab"},
    {"host": "172.16.20.230", "user": "elab"},
    {"host": "172.16.20.81", "user": "elab"},
    {"host": "172.16.20.94", "user": "ctf"},
    {"host": "172.16.20.152", "user": "ctf"},
    {"host": "172.16.20.63", "user": "ctf"},
]
COMMON_PASSWORD = ""  # 所有服务器共用密码
REMOTE_DIR = "/var/www/html"              # 远程目标目录
LOCAL_BASE_DIR = "./sourceCode"     # 本地存储根目录
# ======================

def download_folder(sftp, remote_path, local_path):
    """递归下载远程目录及其内容"""
    os.makedirs(local_path, exist_ok=True)
    
    for entry in sftp.listdir_attr(remote_path):
        remote_full = f"{remote_path}/{entry.filename}"
        local_full = os.path.join(local_path, entry.filename)
        
        if stat.S_ISDIR(entry.st_mode):  # 处理子目录
            download_folder(sftp, remote_full, local_full)
        else:  # 下载文件
            try:
                sftp.get(remote_full, local_full)
                print(f"✓ 下载成功: {remote_full}")
            except Exception as e:
                print(f"✗ 下载失败 [{remote_full}]: {str(e)}")

def process_server(server):
    """处理单个服务器的下载任务"""
    host = server["host"]
    user = server["user"]
    local_dir = os.path.join(LOCAL_BASE_DIR, f"{user}@{host}")
    
    print(f"\n🔗 连接服务器: {user}@{host}")
    try:
        # 创建SSH客户端
        ssh = paramiko.SSHClient()
        ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        
        # 建立连接
        ssh.connect(
            hostname=host,
            username=user,
            password=COMMON_PASSWORD,
            timeout=10
        )
        
        # 创建SFTP会话
        with ssh.open_sftp() as sftp:
            print(f"⬇️ 开始下载: {REMOTE_DIR} -> {local_dir}")
            download_folder(sftp, REMOTE_DIR, local_dir)
            
    except paramiko.AuthenticationException:
        print(f"⛔ 认证失败: {user}@{host} (请检查密码)")
    except Exception as e:
        print(f"⚠️ 连接错误 [{host}]: {str(e)}")
    finally:
        ssh.close() if 'ssh' in locals() else None

if __name__ == "__main__":
    print(f"🚀 开始从 {len(SERVERS)} 台服务器下载文件...")
    os.makedirs(LOCAL_BASE_DIR, exist_ok=True)
    
    # 创建并启动线程
    threads = []
    for server in SERVERS:
        t = threading.Thread(target=process_server, args=(server,))
        t.start()
        threads.append(t)
    
    # 等待所有线程完成
    for t in threads:
        t.join()
    
    print("\n✅ 所有任务完成! 文件已保存至:", os.path.abspath(LOCAL_BASE_DIR))