import requests
import datetime
import json
from collections import defaultdict
import os
import re
from pypinyin import pinyin

owner = "HEUOpenResource"
repo = "heu-icicles"
token = os.environ["TOKEN"]
api_url = f"https://api.github.com/repos/{owner}/{repo}/git/trees/main?recursive=1"
headers = {"Authorization": f"token {token}"}


def get_rate_limit_status(headers):
    """获取并打印GitHub API调用次数限制的状态，使用北京时间显示限额重置时间"""
    limit_url = "https://api.github.com/rate_limit"
    response = requests.get(limit_url, headers=headers)
    if response.status_code == 200:
        limits = response.json()
        print("调用限额：", limits["rate"]["limit"])
        print("剩余调用次数：", limits["rate"]["remaining"])
        reset_timestamp = response.headers["X-RateLimit-Reset"]
        reset_time_utc = datetime.datetime.utcfromtimestamp(int(reset_timestamp))
        reset_time_bj = reset_time_utc + datetime.timedelta(hours=8)
        print("限额将于北京时间", reset_time_bj, "重置")
    else:
        print("无法获取限制状态信息。")


def get_repo_tree(api_url, headers):
    """获取并返回GitHub仓库的文件和目录结构"""
    print("\n调用前状态：")
    get_rate_limit_status(headers)
    response = requests.get(api_url, headers=headers)
    if response.status_code == 200:
        print("\n调用后状态：")
        get_rate_limit_status(headers)
        return response.json()["tree"]
    else:
        print(f"错误：{response.status_code}")
        return []


def print_tree_to_file(tree, filename):
    """将仓库的文件和目录结构写入指定文件中"""
    tree.sort(key=lambda x: x["path"])
    with open(filename, "w", encoding="utf-8") as file:
        for item in tree:
            level = item["path"].count("/")
            indent = "    " * level
            file.write(f"{indent}{item['path'].split('/')[-1]}\n")


def save_tree_to_file(tree, filename="tree.json"):
    with open(filename, "w", encoding="utf-8") as f:
        json.dump(tree, f, indent=4, ensure_ascii=False)  # ensure_ascii 设置为 False


def create_download_link_github(path):
    return f"https://raw.githubusercontent.com/HEUOpenResource/heu-icicles/main/{path}"


def create_download_link_gitee(path):
    return f"https://gitee.com/HEUOpenResource/heu-icicles/raw/main/{path}"


def create_download_link_ghproxy(path):
    return f"https://mirror.ghproxy.com/https://raw.githubusercontent.com/HEUOpenResource/heu-icicles/main/{path}"


def create_download_link_kokomi0728(path):
    return f"https://ghproxy.kokomi0728.eu.org/https://raw.githubusercontent.com/HEUOpenResource/heu-icicles/main/{path}"


def generate_markdown_for_subject(subject_name, subject_tree_data):
    markdown_content = ""
    stack = [(item, "") for item in subject_tree_data]
    while stack:
        item, current_path = stack.pop()

        path = current_path + "/" + item["path"] if current_path else item["path"]

        if item["type"] == "tree":
            markdown_content = (
                f"{'#' * (path.count('/') + 1)} {path}\n\n" + markdown_content
            )
            if "tree" in item:
                stack.extend((child, path) for child in reversed(item["tree"]))
            continue

        filename = path.split("/")[-1]
        size_in_mb = item["size"] / (1024 * 1024)  # Convert bytes to MB
        download_link_github = create_download_link_github(path)
        download_link_gitee = create_download_link_gitee(path)
        download_link_ghproxy = create_download_link_ghproxy(path)
        download_link_kokomi0728 = create_download_link_kokomi0728(path)
        markdown_content = (
            f"- [{filename}]({download_link_github}) ({size_in_mb:.8f} MB) [在线预览]({download_link_gitee}) [备用链接1]({download_link_ghproxy}) [备用链接2]({download_link_kokomi0728}) \n"
            + markdown_content
        )

    return markdown_content


def update_index_file():
    def download_file(url, save_path):
        response = requests.get(url)
        with open(save_path, "wb") as f:
            f.write(response.content)

    # 文件的 URL 和保存路径
    url = "https://raw.githubusercontent.com/HEUOpenResource/heu-icicles/main/README.md"
    temp_file_path = "temp/README.md"
    index_file_path = "docs/index.md"

    # 创建 temp 文件夹（如果不存在）
    if not os.path.exists("temp"):
        os.makedirs("temp")

    # 下载 README.md 文件到 temp 文件夹
    download_file(url, temp_file_path)

    # 将 temp 文件夹中的 README.md 文件覆盖到 docs 文件夹中的 index.md 文件
    os.replace(temp_file_path, index_file_path)
    print("仓库根目录下的README.md文件已经成功覆盖到 docs 文件夹中的 index.md 文件")


def download_and_add_readme(folder_path, output_folder):

    # 创建保存 README 文件的文件夹
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    # 定义一个函数来下载 README 文件
    def download_readme(link, source_file):
        # 检查链接是否以指定前缀开头
        if link.startswith("https://raw.githubusercontent.com"):
            response = requests.get(link)
            if response.status_code == 200:
                # 从链接中获取文件名
                filename = os.path.basename(source_file).split(".")[
                    0
                ]  # 使用来源文件的前缀作为文件名的前缀
                filename = f"{filename}_README.md"
                # 保存文件到 "readme" 文件夹中，并记录来源文件名
                with open(
                    os.path.join(output_folder, filename), "w", encoding="utf-8"
                ) as f:
                    f.write(response.text)
                    f.write("\n\n")
                print(f"Downloaded: {filename} (from {source_file})")
                return response.text
            else:
                print(f"Failed to download: {link}")
        else:
            ##print(f"Skipped downloading: {link} as it doesn't start with 'https://raw.githubusercontent.com'")
            pass
            return None

    # 遍历文件夹中的所有文件
    for root, dirs, files in os.walk(folder_path):
        # for root, files in os.walk(folder_path):
        for file in files:
            if file.endswith(".md"):
                file_path = os.path.join(root, file)
                with open(file_path, "r", encoding="utf-8") as f:
                    content = f.readlines()
                # 使用正则表达式查找下载链接
                updated_content = []
                for line in content:
                    download_match = re.search(r"\[.*?\]\((.*?)\)", line)
                    if download_match and "README.md" in download_match.group(1):
                        # 如果是包含 README.md 下载链接的行，跳过该行
                        continue
                    updated_content.append(line)

                # 将更新后的内容写回到来源文件中
                with open(file_path, "w", encoding="utf-8") as f:
                    f.writelines(updated_content)

                download_links = re.findall(r"\[.*?\]\((.*?)\)", "".join(content))
                # 遍历找到的下载链接
                for link in download_links:
                    if "README.md" in link:
                        # 下载 README 文件并记录来源文件
                        readme_content = download_readme(link, file_path)
                        if readme_content:
                            # 将下载的内容拼接到来源文件的末尾
                            with open(file_path, "a", encoding="utf-8") as f:
                                f.write("\n\n")
                                f.write(readme_content)


def categorize_and_generate_markdown(tree_data, store_path):
    subject_to_files = defaultdict(list)

    for item in tree_data:
        subject = item["path"].split("/")[0]
        if subject.lower() not in {"license", "readme.md"}:
            subject_to_files[subject].append(item)

    if not os.path.exists(store_path):
        os.mkdir(store_path)

    for subject, subject_tree_data in subject_to_files.items():
        output_file_name = os.path.join(store_path, f"{subject}.md")
        markdown_content = generate_markdown_for_subject(subject, subject_tree_data)

        with open(output_file_name, "w", encoding="utf-8") as file:
            file.write(markdown_content)

        print(f"Generated Markdown file: {output_file_name}")


def delete_non_index_md_files(folder_path="docs"):
    # 检查文件夹是否存在
    if not os.path.exists(folder_path):
        print(f"文件夹 '{folder_path}' 不存在。")
        return

    # 遍历文件夹中的所有文件
    for filename in os.listdir(folder_path):
        file_path = os.path.join(folder_path, filename)
        # 如果是一个文件而且不是 index.md，就删除它
        if (
            os.path.isfile(file_path)
            and filename.endswith(".md")
            and filename != "index.md"
        ):
            os.remove(file_path)
            print(f"已删除文件: {file_path}")


def create_md_files():
    with open("tree.json", "r", encoding="utf-8") as file:
        tree_data = json.load(file)

    categorize_and_generate_markdown(tree_data, "docs")


def update_mkdocs_nav(docs_folder, file_path):
    # 获取docs文件夹下所有md文件，但忽略index.md文件
    docs_files = [
        file
        for file in os.listdir(docs_folder)
        if file.endswith(".md") and file != "index.md"
    ]
    docs_files.sort(key=lambda x: pinyin(x))
    docs_files.reverse()
    try:
        with open(file_path, "r", encoding="utf-8") as f:
            lines = f.readlines()
    except FileNotFoundError:
        print("文件未找到。")
        return
    except UnicodeDecodeError:
        print("无法解码文件。")
        return

    # 找到nav段的起始和结束位置
    nav_start = None
    nav_end = None
    for i, line in enumerate(lines):
        if "nav:" in line:
            nav_start = i
        elif nav_start is not None and nav_end is None and line.strip() == "":
            nav_end = i
    if nav_start is None:
        print("未找到nav段。")
        return

    # 删除nav段的内容(保留前两行)
    lines[nav_start + 2 : nav_end] = []

    # 写入新的nav段，挨个添加md文档，格式：- 文档名称: 文档名称.md
    for file in docs_files:
        lines.insert(nav_start + 2, f"  - {file.split('.')[0]}: {file}\n")

    # 写入修改后的文件
    with open(file_path, "w", encoding="utf-8") as f:
        f.writelines(lines)


def beautify_md_files(folder_path):
    # 获取文件夹中的所有 Markdown 文件
    md_files = [f for f in os.listdir(folder_path) if f.endswith(".md")]

    # 遍历每个 Markdown 文件
    for md_file in md_files:
        md_file_path = os.path.join(folder_path, md_file)
        with open(md_file_path, "r", encoding="utf-8") as file:
            md_content = file.readlines()

        modified_content = []
        # 处理每一行内容
        for line in md_content:
            # 使用正则表达式匹配标题行，并替换其中的内容
            modified_line = re.sub(r"(#+)\s(.+)/(.+)", r"\1 \3", line)
            modified_content.append(modified_line)

        # 将修改后的内容写回文件
        with open(md_file_path, "w", encoding="utf-8") as file:
            file.writelines(modified_content)


def add_author_information(author_file_path="author.md"):
    # 读取author.md中的内容
    with open(author_file_path, "r", encoding="utf-8") as author_file:
        author_content = author_file.read()

    # 遍历docs文件夹中的所有Markdown文件
    for root, dirs, files in os.walk("docs"):
        for file in files:
            if file.endswith(".md"):
                file_path = os.path.join(root, file)
                # 读取Markdown文件内容
                with open(file_path, "r", encoding="utf-8") as md_file:
                    md_content = md_file.read()
                # 将author.md中的内容拼接到Markdown文件内容中
                new_content = md_content + "\n\n" + author_content
                # 写入拼接后的内容到Markdown文件中
                with open(file_path, "w", encoding="utf-8") as md_file:
                    md_file.write(new_content)


tree = get_repo_tree(api_url, headers)

if tree:
    print_tree_to_file(tree, "context.txt")
    save_tree_to_file(tree)
    # 删除非 index.md 的所有 .md 文件
    delete_non_index_md_files()
    update_index_file()
    create_md_files()
    download_and_add_readme("docs", "temp")
    beautify_md_files("docs")
    update_mkdocs_nav("docs", "mkdocs.yml")
    add_author_information()
