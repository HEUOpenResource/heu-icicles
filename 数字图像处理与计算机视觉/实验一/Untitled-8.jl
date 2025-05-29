using PyCall
using TyImages  # 如果 TyImages 是必需的，请确保已安装
cv = pyimport("cv2")

# 从文件中读取视频
cap = cv.VideoCapture("D:\\2345Downloads\\Syslab\\Syslab 2023b\\Examples\\project_video.mp4")

# 检查视频是否成功打开
if !cap.isOpened()
    error("无法打开视频文件！")
end

# 获取输入视频的宽度、高度和帧率
width = Int(cap.get(cv.CAP_PROP_FRAME_WIDTH))
height = Int(cap.get(cv.CAP_PROP_FRAME_HEIGHT))
fps = cap.get(cv.CAP_PROP_FPS)

# 创建输出目录
output_dir = "test"
if !isdir(output_dir)
    mkdir(output_dir)
end

# 创建视频写入对象
fourcc = cv.VideoWriter_fourcc("m", "p", "4", "v")
out = cv.VideoWriter(joinpath(output_dir, "output.mp4"), fourcc, fps, (width, height))

# 获取视频的总帧数
total_frames = Int(cap.get(cv.CAP_PROP_FRAME_COUNT))
println("视频总帧数：", total_frames)

# 读取并处理前 100 帧
for i = 1:100
    # 读取视频的每一帧
    ret, frame = cap.read()

    # 检查帧是否读取成功
    if !ret
        println("无法接收帧（视频流结束？）。退出...")
        break
    end

    # 将帧写入输出视频
    out.write(frame)

    # 保存帧为图像文件
    filename = joinpath(output_dir, string(lpad(i, 4, "0"), ".jpg"))
    cv.imwrite(filename, frame)
end

# 释放资源
cap.release()
out.release()
println("视频处理完成！")