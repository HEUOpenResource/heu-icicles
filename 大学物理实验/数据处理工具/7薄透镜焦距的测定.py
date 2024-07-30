"""
这是薄透镜焦距的计算程序，大家只需要把数据代入区的函数的实参和变量的数据替换成自己的就可以啦。

注意：
    1. 参数的单位是 cm。
    2. 注意光具座读数时原点的选取。一般从左往右是物屏到像屏，如果从右往左的顺序，则需要将参数中的位置取反。
    3. 参数都是测量后的平均值。
    4. 相对误差和不确定度的公式我也不会，我是照小口袋的模板仿写出来的，可能公式会不太严谨。
    5. 在“像距”的命名上，书中代表的字母是 A2, 但我不小心打错成 M 了，但和书中表格的顺序没有变，大家请放心代入。

"""


def calc_f_by_Mirror(l1, A):
    """
    对象：凸透镜
    方法：平面镜法
    l1: 凸透镜的位置
    A: 物的位置
    返回值：焦距
    """
    return l1 - A


def calc_f_by_Position_Based(l1, A, M):
    """
    对象：凸透镜
    方法：物距像距法
    公式: 1/p +1/q = 1/f
    l1: 凸透镜的位置
    A: 物的位置
    M: 像屏的位置(表格中的 A2)
    返回值：焦距
    """
    p = l1 - A
    q = M - l1
    return p * q / (p + q)


def calc_f_by_Conjugate(l1, l2, A, M):
    """
    对象：凸透镜
    方法：共轭法
    公式: f = (d**2 + l**2)/4*d
    l1: 凸透镜成放大实像的位置
    l2: 凸透镜成缩小实像的位置
    A: 物的位置
    M: 像屏的位置(表格中的 A2)
    返回值：焦距
    """
    d = M - A
    l = l2 - l1
    return (d**2 + l**2) / (4 * d)


def calc_f_by_Position_Based_2(D, E, l2):
    """
    对象：凹透镜
    方法：物距像距法
    公式: 1/q - 1/|p| = 1/f
    D: 物屏的第一次实验的位置
    E: 物屏的第二次实验的位置
    l2: 凹透镜的位置
    返回值：焦距
    """
    p = D - l2
    q = E - l2
    return abs(p) * q / (abs(p) - q)


def calc_Sx(xi, x):
    """
    计算偏差
    """
    sum = 0
    for i in xi:
        sum += (i - x) ** 2
    return (sum / (6 - 1)) ** (1 / 2)


def calc_Uncertainty_f(l2, D, E):
    """
    计算不确定度
    """
    return (D - l2) * (E - l2) / (D - E)


def calc_delta_f(l2, D, E, delta_D, delta_E, delta_l2):
    temp1 = ((E - l2) / (D - E)) ** 4 * (delta_D**2)
    temp2 = ((D - l2) / (D - E)) ** 4 * (delta_E**2)
    temp3 = ((2 * l2 - D - E) / (D - E)) ** 2 * (delta_l2**2)
    return (temp1 + temp2 + temp3) ** (1 / 2)


def calc_Er(delta_f, Uncertainty_f):
    """
    计算相对误差
    """
    return delta_f / Uncertainty_f * 100


if __name__ == "__main__":
    # =============================数据代入区 ==============================
    # 凸透镜焦距的测定
    test_1 = calc_f_by_Mirror(56.35, 36.00)  # 这里不需要把表格中的 M 代入，前两个参数就可以。
    test_2 = calc_f_by_Position_Based(72.28, 27.50, 108.00)
    test_3 = calc_f_by_Conjugate(63.62, 72.30, 27.50, 108.00)

    # 凹透镜焦距的测定
    test_4 = calc_f_by_Position_Based_2(-32.40, -23.83, -41.80)

    # 表 15-4 物距像距法法测凹透镜焦距数据记录
    # 由于我摆放的位置与原点相反，所以需要将参数取反
    Di = [-32.00, -32.50, -32.70, -32.30, -32.20, -32.70]
    D = sum(Di) / len(Di)  # 自动计算平均值
    Ei = [-23.50, -23.00, -25.00, -24.00, -23.50, -24.00]
    E = sum(Ei) / len(Ei)  # 自动计算平均值
    l2 = -41.80
    # ============================ 数据代入区结束 =============================

    # 计算 Δ
    delta_l2 = 0.05  # 钢尺的误差/cm
    Dx = calc_Sx(Di, D)
    Ex = calc_Sx(Ei, E)
    delta_D = (Dx**2 + delta_l2**2) ** (1 / 2)
    delta_E = (Ex**2 + delta_l2**2) ** (1 / 2)
    delta_f = calc_delta_f(l2, D, E, delta_D, delta_E, delta_l2)
    Uncertainty_f = calc_Uncertainty_f(l2, D, E)
    Er = -calc_Er(delta_f, Uncertainty_f)

    print("凸透镜焦距的测定：\n")
    print("\t1. 平面镜法：%.2f\n" % test_1)
    print("\t2. 物距像距法: %.2f\n" % test_2)
    print("\t3. 共轭法: %.2f\n" % test_3)

    print("凹透镜焦距的测定：\n")
    print("\t1. 平面镜法：该实验已取消\n")
    print("\t2. 物距像距法: %.2f\n" % test_4)

    print("不确定度：\n")
    print("\t相对误差: %.2f%%\n" % Er)
    print("\t故 f = %.2f +/- %.2f\n" % (test_4, delta_f))
