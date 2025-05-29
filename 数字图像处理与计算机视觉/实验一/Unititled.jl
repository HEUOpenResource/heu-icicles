#计算并显示图像的直方图，直方图均衡化
using PyCall
using TyImages
cv2 = pyimport("cv2")
# 读取图像
image = cv2.imread("D:\\2345Downloads\\Syslab\\Syslab 2023b\\Examples\\test1.jpg", 0)#以灰度方式读图像
# 计算并显示图像的直方图
imgHist = imhist(image, fig=true)
# imgHist是一个包括两个元素的元组，每个元素是个一维向量
# 第一个元素是整数类型的直方图向量,可以用plot显示
a = imgHist[1];
plot(a)
# 第二个元素是浮点数类型的直方图向量,可以用于计算
a = imgHist[2];
# 直方图均衡化
imageEq = histeq(image);
figure()
imgHist1 = imhist(imageEq, fig=true)
