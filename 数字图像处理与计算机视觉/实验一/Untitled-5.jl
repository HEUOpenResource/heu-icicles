#颜色空间转换:https://cloud.tencent.com/developer/article/1796362
using PyCall
using TyImages #同元图像处理工具箱
cv2 = pyimport("cv2")
#从文件中读取图像
img = cv2.imread("D:\\2345Downloads\\Syslab\\Syslab 2023b\\Examples\\test1.jpg");
#将BGR格式的图像转成RGB格式
#imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB);
#将BGR格式的图像转成HSV格式
imgHSV = cv2.cvtColor(img, cv2.COLOR_BGR2HSV);
imshow(imgHSV)