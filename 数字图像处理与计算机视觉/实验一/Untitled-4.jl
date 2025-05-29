# 傅里叶变换
using PyCall
using TyImages #同元图像处理工具箱
cv2 = pyimport("cv2")
#从文件中读取图像
img = cv2.imread("D:\\2345Downloads\\Syslab\\Syslab 2023b\\Examples\\test1.jpg", 0);
dft = cv2.dft(float.(img), flags=cv2.DFT_COMPLEX_OUTPUT);
# 计算幅度谱
mag = cv2.magnitude(dft[:, :, 1], dft[:, :, 2]);
dft_shift = log.(fftshift(mag))#fftshift同元工具箱函数,中心变换
imshow(dft_shift, [])
# 计算相位谱
pha = cv2.phase(dft[:, :, 1], dft[:, :, 2]);
pha_shift = fftshift(pha);
imshow(pha_shift,[])