"""
本来，学长做的 excel 表格已经满足了这个实验的计算要求，只需把表格里的数据代入即可得到书上所说的所有的结果。

可是，我们的老师给了我们新的规定：
由于是双人实验，为避免两人数据过度雷同，要求两个人分别使用不同的方法去计算不确定度，而用对方的另一种方法得出结果。

原规定如下，
数据处理要求:
    1. 单座位号同学。详细处理共振干涉法数据(包括不确定度估计);相位比较法数据计算出波长、速度。
    2. 双座位号同学。详细处理相位比较法数据(包括不确定度估计);共振干涉法数据计算出波长、速度。
    3. 其他处理内容相同

可是，无论是书上的公式，还是学长给的表格，都无法满足老师对双座位号同学的这个规定。

所以下面的这份代码，是专为处理相位比较法数据(包括不确定度估计)准备的。

至于单座位号同学嘛，直接用学长的 excel 表格就可以啦，内含公式，可直接计算。

注意：
    数据代入的单位是 mm。
"""

import statistics

# 常量设置区
f = 38.31 * (10**3)
delta_f = 0.05
delta_0 = 0.02
t = 24.5
T = 273.15
v_0 = 331.45

# =============================数据代入区 ================================
# 测量数据
Si = [108.94, 118.00, 127.10, 136.12, 145.40, 154.32, 163.48, 172.46, 181.62, 190.60]
Sj = [199.72, 208.82, 217.94, 227.00, 236.00, 245.10, 255.50, 261.42, 270.50, 279.62]
# ============================ 数据代入区结束 =============================

# Sj - Si
Sj_i = [round(Sj[i] - Si[i], 2) for i in range(10)]

# Sj-i 的平均值
mean_Sj_i = statistics.mean(Sj_i)

# ΔSj-i
delta_Sj_i = [item - mean_Sj_i for item in Sj_i]

# A 类不确定度
delta_A = statistics.stdev(Sj_i)

# B 类不确定度
delta_B = ((delta_0**2) * 2) ** (1 / 2)

# 10L 的总不确定度
delta_10L = (delta_A**2 + delta_B**2) ** (1 / 2)

# 波长
wavelength = mean_Sj_i / 10

# Δ波长
delta_wavelength = delta_10L / 10

# 波速
v = wavelength * f * 0.001

# Er/E
Er_div_E = ((delta_wavelength / wavelength) ** 2 + (delta_f / f) ** 2) ** (1 / 2)

# 波速 +/- Δv
delta_v = v * Er_div_E

# 理论值
theory_v = v_0 * (1 + t / T) ** (1 / 2)

# 与理论值的差值 Δv`
delta_theory = abs(theory_v - v)

# Er`
Er_theory = delta_theory / theory_v

if __name__ == "__main__":
    # 输出结果
    print("\n")
    print("相位比较法测声波波长：")
    print("\n")
    print("\t10L 的 A 类不确定度: {:.2f}mm\n".format(delta_A))
    print("\t10L 的 B 类不确定度: {:.2f}mm\n".format(delta_B))
    print("\t10L 的 总不确定度: {:.2f}mm\n".format(delta_10L))
    print("\t波长 = %.2f +/- %.2f mm\n" % (wavelength, delta_wavelength))
    print("\n")
    print("相位比较法测声波波速和不确定度：")
    print("\n")
    print("\tv = %.2f +/- %.2f m/s\n" % (v, delta_v))

    print("\t理论值: {:.2f}m/s\n".format(theory_v))
    print("\t与理论值的差值 Δv`: {:.2f}m/s\n".format(delta_theory))
    print("\tEr`: {:.2f}%\n".format(Er_theory * 100))
