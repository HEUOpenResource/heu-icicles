#通过卷积处理图像,图像锐化
using PyCall
using TyImages #同元图像处理工具箱
cv2 = pyimport("cv2")
#从文件中读取图像
img = cv2.imread("D:\\2345Downloads\\Syslab\\Syslab 2023b\\Examples\\test1.jpg", 0);
#拉普拉斯算子
ker = [0 -1 0; -1 4 -1; 0 -1 0]
imgSharp = cv2.filter2D(img, Int32(-1), ker)
imshow(imgSharp)
#Sobel算子
ker = [1 2 1; 0 0 0; -1 -2 -1]
img1 = cv2.filter2D(img, Int32(-1), ker)
img2 = cv2.filter2D(img, Int32(-1), transpose(ker))
imgSharp = cv2.add(abs.(img1),abs.(img2))
imshow(imgSharp)