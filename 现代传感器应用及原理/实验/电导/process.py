import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# 读取二进制文件数据
file_path = r'C:\Users\HanDong\Desktop\电导\1_p_1000hz.bin'

with open(file_path, 'rb') as file:
    binary_data = file.read()

# 将二进制数据解码为32位浮点数数组
data_array = np.frombuffer(binary_data, dtype=np.float32)

# 将数据重塑为三列（AN1, AN3, AN2），如果不满足3的倍数，则舍弃多余的元素
# if len(data_array) % 3 == 0:
#     reshaped_data = data_array.reshape(-1, 3)
# else:
#     reshaped_data = data_array[:-1].reshape(-1, 3)  # 舍弃多余的数据
reshaped_data = data_array.reshape(-1, 8) * 1e22
# 提取AN1, AN3, AN2
AN1 = reshaped_data[:, 0]
AN3 = reshaped_data[:, 1]
AN2 = reshaped_data[:, 2]

# 计算电流（I）、压降（V）和电阻（R）
I = AN1 / 10000  # 将AN1除以10K转换为电流
V = AN3 - AN2    # 计算压降
R = np.where(I != 0, V / I, np.nan)  # 避免除以零的情况

# 绘制AN1, AN2, AN3的波形图
plt.figure(figsize=(12, 6))
plt.plot(AN1, label='AN1')
plt.plot(AN2, label='AN2', linestyle='--')
plt.plot(AN3, label='AN3', linestyle=':')
plt.title('Waveforms of AN1, AN2, and AN3')
plt.xlabel('Index')
plt.ylabel('Amplitude')
plt.legend()
plt.show()

# 计算电流、压降和电阻的平均值
mean_current = np.nanmean(I)
mean_voltage_drop = np.nanmean(V)
mean_resistance = np.nanmean(R)

# 输出结果
print("平均电流 (I):", mean_current)
print("平均压降 (V):", mean_voltage_drop)
print("平均电阻 (R):", mean_resistance)
