#通过卷积处理图像,图像平滑
using PyCall
using TyImages #同元图像处理工具箱
cv2 = pyimport("cv2")
#从文件中读取图像
img = cv2.imread("D:\\2345Downloads\\Syslab\\Syslab 2023b\\Examples\\test1.jpg");
# 定义一个5*5的平滑掩模
ker = ones(Float32, 5, 5) / 25
imgRGB = cv2.filter2D(img, Int32(-1), ker)#第2个参数是新图像深度，-1表示与原图像相同
cv2.namedWindow("org")
cv2.imshow("org", img)
cv2.namedWindow("out1")
cv2.imshow("out1", imgRGB)
ker = [1 2 1; 0 0 0; -1 -2 -1]
imgRGB = cv2.filter2D(img, Int32(-1), ker)
cv2.namedWindow("out2")
cv2.imshow("out2", imgRGB)
# 通过高斯掩模模糊图像
gaussImg = cv2.GaussianBlur(img, (5, 5), 0);
# 通过双边滤波平滑图像
bilaImg = cv2.bilateralFilter(img, 9, 75, 75);
# 中值滤波平滑图像
noiseImg = imnoise(img, "salt & pepper", 0.1);
medImg = cv2.medianBlur(noiseImg, 5);