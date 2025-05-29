#阈值分割和形态学处理
using PyCall
using TyImages
cv2 = pyimport("cv2")

img = cv2.imread("D:\\2345Downloads\\Syslab\\Syslab 2023b\\Examples\\test1.jpg", 0)
#阈值分割，阈值为150，产生的结果是个两个元素的元组
binTuple = cv2.threshold(img,150,255,cv2.THRESH_BINARY);
#第2个元素是结果图像
binImg = binTuple[2];
#结构元素
kernel = ones(UInt8,3, 3)
#膨胀处理
dltImg = cv2.dilate(binImg, kernel, iterations=1);
#腐蚀处理，(-1, -1)表示从中心像素处理
erdImg = cv2.erode(dltImg, kernel, (-1, -1), iterations=1);
figure()
imshow(dltImg)
figure()
imshow(erdImg)