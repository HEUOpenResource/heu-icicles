#边缘提取:
using PyCall
using TyImages
cv2 = pyimport("cv2")
# 读取一张图片
img = cv2.imread("D:\\2345Downloads\\Syslab\\Syslab 2023b\\Examples\\test1.jpg");
# 使用Canny函数进行边缘检测https://blog.csdn.net/qq_28949847/article/details/129537581
edges = cv2.Canny(img, 100, 200);
# 显示结果
imshow(edges)
