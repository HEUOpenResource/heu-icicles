'''
这是薄透镜焦距的计算程序。

注意：
    1. 参数的单位是 cm。
    2. 注意光具座读数时原点的选取。一般从左往右是物屏到像屏，如果从右往左的顺序，则需要将参数中的位置取反。
    3. 参数都是测量后的平均值。
'''

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
    M: 像屏的位置
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
    M: 像屏的位置
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


if __name__ == "__main__":
    test_1 = calc_f_by_Mirror(56.35, 36.00)
    test_2 = calc_f_by_Position_Based(72.28, 27.50, 108.00)
    test_3 = calc_f_by_Conjugate(63.62, 72.30, 27.50, 108.00)
    test_4 = calc_f_by_Position_Based_2(-32.40, -23.83, -41.80)

    print("凸透镜焦距的测定：\n")
    print("\t1. 平面镜法：%.2f\n" % test_1)
    print("\t2. 物距像距法: %.2f\n" % test_2)
    print("\t3. 共轭法: %.2f\n" % test_3)
    
    print("凹透镜焦距的测定：\n")
    print("\t1. 平面镜法：该实验已取消\n")
    print("\t2. 物距像距法: %.2f\n" % test_4)
