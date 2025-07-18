using Pkg

# 检查并安装 PyCall 包
if !haskey(Pkg.dependencies(), Base.UUID("438e738f-606a-5dbb-bf0a-cddfbfd45ab0"))  # PyCall 的 UUID
    println("PyCall 包未安装，正在安装...")
    Pkg.add("PyCall")
end

# 动态加载 PyCall
if !isdefined(Main, :PyCall)
    @eval using PyCall
end

# 检查并安装 Images 包
if !haskey(Pkg.dependencies(), Base.UUID("916415d5-f1e6-5110-898d-aaa5f9f070e0"))  # Images 的 UUID
    println("Images 包未安装，正在安装...")
    Pkg.add("Images")
end

# 动态加载 Images
if !isdefined(Main, :Images)
    @eval using Images
end

using PyCall:PyReverseDims

# 检查并安装 cv2 模块
try
    global cv2 = pyimport("cv2")  # 使用 global 确保 cv2 在全局作用域中定义
catch e
    println("cv2 模块未安装，正在尝试安装...")
    pyimport_conda("cv2", "opencv")
    global cv2 = pyimport("cv2")  # 再次使用 global 确保定义
end

#录像切片函数
function process_video(input_path,output_path;process_func=identity)
    cap=cv2.VideoCapture(input_path)
    if !cap.isOpened()
        error("video is empty")
    end

    width=Int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    height=Int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    fps=cap.get(cv2.CAP_PROP_FPS)
    total_frames=Int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

    fourcc=cv2.CAP_OPENCV_MJPEG
    out=cv2.VideoWriter(output_path,fourcc,fps,(width,height))

    frame_count=0

    try
        while true
            ret,frame=cap.read()
            if !ret
                break
            end

            frame_count+=1
            if frame_count%100==0
                println("$frame_count / $total_frames")
            end

            processed_frame=process_func(frame)
            out.write(processed_frame)
        end

    finally
        cap.release()
        out.release()
        println("work done")
    end

    return frame_count
end

#数组转换函数，将julia风格的列主序数组转化为python风格的行主序数组
function julia_py(array)
    rimg = permutedims(array, ndims(array):-1:1)
    pyarr = PyReverseDims(rimg)
    return pyarr
end

function workwork(frame)
    height, width = size(frame)[1:2]
    
    # 设置中值滤波器的核大小
    ksize = 5  # 默认值为 5，可根据需求调整

    #设置掩码，消除视频中汉字的影响
    mask=zeros(UInt8,height,width)
    y1=165
    y2=485
    x1=360
    x2=700
    mask[y1:y2,x1:x2] .= 1

    #灰度分割
    gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    masked_gray=gray .* mask
    #中值滤波
    blurred=cv2.medianBlur(masked_gray,ksize)

    #sobel算子提取边缘
    grad_x=cv2.Sobel(blurred,cv2.CV_64F,1,0)
    grad_y=cv2.Sobel(blurred,cv2.CV_64F,0,1)
    abs_grad_x=cv2.convertScaleAbs(grad_x)
    abs_grad_y=cv2.convertScaleAbs(grad_y)
    gradient=cv2.addWeighted(abs_grad_x,0.5,abs_grad_y,0.5,0)
    normSobel=255*gradient ./maximum(gradient)
    normSobel=round.(normSobel)

    #二值化边缘图像
    scaled_sobel=convert.(UInt8,normSobel)
    hsblBin=(scaled_sobel.>=68)
    edges=UInt8.(hsblBin) .* 255
    edges_np=cv2.convertScaleAbs(julia_py(edges))
    
    #霍夫变换寻找最大凸包
    contours,_=cv2.findContours(edges_np,cv2.RETR_LIST,cv2.CHAIN_APPROX_NONE)

    valid_contours=[c for c in contours if cv2.contourArea(c) > 15]
    
    #输出到原图像中
    if !isempty(valid_contours)
        all_points=vcat([reshape(c,:,2) for c in valid_contours]...)
        combined_hull=cv2.convexHull(julia_py(all_points))
        result_np=cv2.drawContours(julia_py(frame),[combined_hull],0,(0,0,255),2)
    end
    
    return result_np
end

process_video("D:\\2345Downloads\\Syslab\\Experiment2.mp4", "D:\\2345Downloads\\Syslab\\test.mp4", process_func=workwork)