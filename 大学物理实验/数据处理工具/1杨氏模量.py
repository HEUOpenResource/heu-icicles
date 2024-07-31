"""
这是拉伸法测量金属丝的杨氏模量的计算程序，大家只需要把数据代入区里的变量的数据替换成自己的就可以啦。

注意：
数据中有一个常量，是Δ仪，是计算不确定度时用到的，但这个常量在书中没有明确给出。

我查了小口袋上的报告，一份报告中，Δ仪是 0.02, 但另一份报告中，Δ仪是 0.004。

我不确定到底取哪个，询问了两位做过的同学，发现她们取的是 0.02, 参考的是第一个报告。

所以，我将 Δ仪由常量区放进了变量区，大家可以根据自己的需要修改这个值。

Δ仪的变量名为delta_0, 在数据修改区的第一行。
"""

# 常量设置
g = 9.8  # 重力加速度
delta_m = 6  # 逐差法结果，来源见课本
PI = 3.14159
delta_L = 2
delta_H = 2
delta_div_F = 0.01  # ΔF/F = 1%

delta_b = 0.03
delta_n0 = 0.5


def calculate_E(delta_m, L, H, D, B, N):
    """
    计算杨氏模量
    :param delta_m: 逐差法结果，来源见课本
    :param L: 金属丝原长 L
    :param H: 垂直距离 H
    :param D: 金属丝直径 d
    :param B: 水平卡座 b 长度
    :param N: 标尺刻度改变量的平均值
    :return: 计算得到的杨氏模量
    """
    # 单位转换
    L = L * 0.001
    H = H * 0.001
    D = D * 0.001
    B = B * 0.001
    N = N * 0.001

    E = (8 * delta_m * g * L * H) / (PI * (D**2) * B * N)
    return E


def calculate_Sx(X, Xi):
    """
    计算 Sn, Sd 与 Sb
    :param X: 平均值
    :param Xi: 数据列表
    :return: Sx
    """
    sum = 0
    for i in range(5):
        sum += (X - Xi[i]) ** 2
        return (sum / 5) ** (1 / 2)


def calculate_delta_N(Sn, detla_yi):
    """
    计算 ΔN
    :param Sn: S_N
    :param detla_yi: Δ仪
    :return: ΔN
    """
    return (Sn**2 + 2 * (detla_yi**2)) ** (1 / 2)


def calculate_delta_d(Sd, detla_yi):
    """
    计算 Δd
    :param Sd: S_d
    :param detla_yi: Δ仪
    :return: Δd
    """
    return (Sd**2 + 2 * (detla_yi**2)) ** (1 / 2)


def calculate_delta_b(Sb, detla_yi):
    """
    计算 Δb
    :param Sb: S_b
    :param detla_yi: Δ仪
    :return: Δb
    """
    return (Sb**2 + (detla_yi**2)) ** (1 / 2)


def calculate_Er(
    delta_div_F, delta_L, L, delta_H, H, delta_d, d, delta_b, b, delta_N, N
):
    """
    计算误差
    :param delta_div_F: ΔF/F = 1%
    :param delta_L: ΔL
    :param L: 金属丝原长 L
    :param delta_H: ΔH
    :param H: 垂直距离 H
    :param delta_d: Δd
    :param d: 金属丝直径 d
    :param delta_b: Δb
    :param b: 水平卡座 b 长度
    :param delta_N: ΔN
    :param N: 标尺刻度改变量的平均值
    :return: 计算得到的误差
    """
    Er_pow2 = (
        (delta_div_F) ** 2
        + (delta_L / L) ** 2
        + (delta_H / H) ** 2
        + 4 * (delta_d / d) ** 2
        + (delta_b / b) ** 2
        + (delta_N / N) ** 2
    )
    return Er_pow2 ** (1 / 2)


if __name__ == "__main__":
    # =============================数据代入区 ==============================
    # Δ仪
    delta_0 = 0.02
    # 表 4-1 一次性测量数据
    L = 742.5
    H = 645.2
    # 表 4-2 金属丝直径 d 及水平卡座 b 长度测量数据
    d0 = 0.02  # 螺旋测微器零差
    Di = [0.658, 0.656, 0.659, 0.659, 0.657, 0.653]  # 金属丝直径 d 六次测量值、
    bi = [53.60, 53.58, 55.54, 55.62, 55.52, 55.56]  # 水平卡座 b 长度六次测量值
    D = sum(Di) / len(Di)  # 平均值
    B = sum(bi) / len(bi)  # 平均值

    # 表 4-3 加减力时标尺刻度与对应拉力的数据（单位是 mm）
    # 加力
    n_up = [47.1, 49.5, 52.1, 54.9, 57.5, 60.1, 63.5, 66.1, 68.9, 71.8, 74.0, 77.2]
    # 减力
    n_down = [47.2, 49.7, 52.3, 55.0, 57.7, 60.6, 63.9, 66.1, 69.4, 72.0, 74.4, 77.2]
    # 平均标尺刻度
    ni = [(n_up[i] + n_down[i]) / 2 for i in range(len(n_up))]
    # 逐差法
    Ni = [(ni[i + 6] - ni[i]) for i in range(6)]
    # 平均值
    N = sum(Ni) / len(Ni)
    # ============================ 数据代入区结束 =============================

    E = calculate_E(delta_m, L, H, D, B, N)  # 计算杨氏模量
    Sn = calculate_Sx(N, Ni)  # 计算 Sn
    Sd = calculate_Sx(D, Di)  # 计算 Sd
    Sb = calculate_Sx(B, bi)  # 计算 Sb
    delta_b = calculate_delta_b(Sb, delta_0)  # 计算 Δb
    delta_d = calculate_delta_d(Sd, delta_0)  # 计算 Δd
    delta_N = calculate_delta_N(Sn, delta_0)  # 计算 ΔN
    Er = calculate_Er(
        delta_div_F, delta_L, L, delta_H, H, delta_d, D, delta_b, B, delta_N, N
    )  # 计算不确定度
    delta_E = Er * E  # 计算 ΔE

    # 输出结果
    print("\n")
    print("杨氏模量：\n")
    print("\tE = {:.2e} N/m^2\n".format(E))

    print("不确定度：\n")
    print("\tSn = {:.4f} mm\n".format(Sn))
    print("\tSd = {:.4f} mm\n".format(Sd))
    print("\tSb = {:.4f} mm\n".format(Sb))
    print("\tΔb = {:.4f} mm\n".format(delta_b))
    print("\tΔd = {:.4f} mm\n".format(delta_d))
    print("\tΔN = {:.4f} mm\n".format(delta_N))
    print("\tΔE/E = {:.2f}%\n".format(delta_E / E * 100))
    print("\tEr = {:.2f}%\n".format(Er * 100))
    print("\tΔE = {:.2e} N/m^2\n".format(delta_E))
