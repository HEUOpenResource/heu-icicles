"""
这是等厚干涉的计算程序，大家只需要把数据代入区的变量的数据替换成自己的就可以啦。
"""

# 常量设置区
L = 0.5893e-6  # 波长
delta_0 = 0.005  # Δ0 = 0.005

# =============================数据代入区 ==============================
# 直径 dm/mm
dm = [8.990, 8.874, 8.761, 8.659, 8.560, 8.447, 8.282, 8.199, 8.102, 7.989]
# 直径 dn/mm
dn = [6.377, 6.222, 6.063, 5.961, 5.792, 5.553, 5.394, 5.291, 5.134, 4.911]
# dm^2 - dn^2
pow_minus_m_n = [dm[i] ** 2 - dn[i] ** 2 for i in range(len(dm))]
# 平均值
avg = sum(pow_minus_m_n) / len(pow_minus_m_n)


# ============================ 数据代入区结束 ===========================
def calculate_R(avg, L):
    """
    计算曲率半径。
    :param avg: 逐差法平均值
    :param L: 波长
    """
    m = 40
    n = 15
    return (0.001 * 0.001) * avg / (4 * (m - n) * L)


def calculate_delta_dmn(delta_0):
    """
    计算dmn的相对不确定度。
    :param delta_0: Δ0 = 0.005
    """
    return (2 * delta_0**2) ** (1 / 2)


def calculate_S(pow_minus_m_n, avg):
    """
    计算S = Δ(dm^2 - dn^2)/Δ0
    :param pow-minus_m_n: dm^2 - dn^2
    :param avg: 逐差法平均值
    """
    return (
        sum([(avg - pow_minus_m_n[i]) ** 2 for i in range(len(pow_minus_m_n))])
        / (len(pow_minus_m_n) - 1)
    ) ** (1 / 2)


def calculate_delta_B(d40, d15, delta_dmn):
    """
    计算ΔB(dm2-dn2)
    :param d40: d40
    :param d15: d15
    :param delta_dmn: 即 calculate_delta_dmn 的函数返回值
    """
    return ((2 * d40 * delta_dmn) ** 2 + (2 * d15 * delta_dmn) ** 2) ** (1 / 2)


def calculate_delta_dm2_minus_dn2(S, delta_B):
    """
    计算Δ(dm2-dn2)
    :param S: 即 calculate_S 的计算结果
    :param delta_B: 即 calculate_delta_B 的计算结果
    """
    return ((S**2) + (delta_B**2)) ** (1 / 2)


def calculate_delta_R(delta_dm2_minus_dn2, L):
    """
    计算ΔR
    :param delta_dm2_minus_dn2: Δ(dm2-dn2)
    :param L: 波长
    """
    m = 40
    n = 15
    return (0.001 * 0.001) * delta_dm2_minus_dn2 / (4 * (m - n) * L)


# 代入计算区
R = calculate_R(avg, L)
delta_dmn = calculate_delta_dmn(delta_0)
S = calculate_S(pow_minus_m_n, avg)
delta_B = calculate_delta_B(dm[0], dn[0], delta_dmn)
delta_dm2_dn2 = calculate_delta_dm2_minus_dn2(S, delta_B)
delta_R = calculate_delta_R(delta_dm2_dn2, L)
Er = 100 * delta_R / R

# 结果展示区
print("结果展示：\n")
print(f"\tR = ({R:.4f} +- {delta_R:.4f}) m\n")

print(f"\tEr = {Er:.3f}%\n")

# 计算不确定度的中间结果
print("计算不确定度的中间结果：\n")
print("\tΔdm,n = {:.4f} mm\n".format(delta_dmn))
print("\tΔS(dm^2-dn^2) = {:.4f} mm\n".format(S))
print("\tΔB(dm^2-dn^2) = {:.4f} mm\n".format(delta_B))
print("\tΔ(dm^2-dn^2) = {:.4f} mm\n".format(delta_dm2_dn2))
print("\tΔR = {:.4f} m\n".format(delta_R))
