using PyCall
using Images
using Plots  # 替代 ImageView，避免预编译问题

# 导入 OpenCV
cv = pyimport("cv2")

# 定义车道线颜色阈值分割函数
function detect_lanes(img_bgr)
    # 将 BGR 转换为 RGB 颜色空间
    img_rgb = cv.cvtColor(img_bgr, cv.COLOR_BGR2RGB)
    
    # 提取 RGB 通道（注意 Julia 数组是列优先，OpenCV 是行优先）
    r = img_rgb[:, :, 1]  # 红通道
    g = img_rgb[:, :, 2]  # 绿通道
    b = img_rgb[:, :, 3]  # 蓝通道

    # 定义白色车道线阈值（R, G, B 均较高）
    white_threshold = (r .>= 200) .& (g .>= 200) .& (b .>= 200)
    
    # 定义黄色车道线阈值（R 和 G 高，B 低）
    yellow_threshold = (r .>= 180) .& (g .>= 160) .& (b .<= 100)
    
    # 合并掩膜（逻辑或运算）
    lane_mask = white_threshold .| yellow_threshold
    
    # 形态学处理：闭运算填补空洞
    kernel = cv.getStructuringElement(cv.MORPH_RECT, (5, 5))
    lane_mask_clean = cv.morphologyEx(lane_mask, cv.MORPH_CLOSE, kernel)
    
    return lane_mask_clean
end

# 主程序
function main()
    # 读取图像
    img = cv.imread("D:\\2345Downloads\\Syslab\\Syslab 2023b\\Examples\\test1.jpg")
    
    # 检测车道线掩膜
    lane_mask = detect_lanes(img)
    
    # 将掩膜转换为 Julia 图像格式（用于显示）
    lane_mask_julia = Gray.(lane_mask)
    
    # 在原图上标记车道线区域（红色覆盖）
    img_marked = cv.cvtColor(img, cv.COLOR_BGR2RGB)
    img_marked[lane_mask, 1] .= 255  # 红色通道设为255
    
    # 显示结果
    plot(
        plot(img_marked, title="车道线检测结果"),
        plot(lane_mask_julia, title="车道线掩膜"),
        layout=(1, 2)
    )
end

# 运行主程序
main()