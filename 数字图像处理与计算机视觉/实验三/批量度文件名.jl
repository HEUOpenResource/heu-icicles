# 定义图像文件扩展名
image_extensions = [".jpg", ".jpeg", ".png", ".bmp", ".tiff", ".gif"]

# 读取文件夹下的所有文件名
folder_path = "E:\\julia\\laneDection-master\\test"
all_files = readdir(folder_path)

# 筛选出图像文件
image_files = filter(file -> any(endswith(lowercase(file), ext) for ext in image_extensions), all_files)

# 打印所有图像文件名
println("图像文件列表:")
foreach(println, image_files)
