"""
这是分光计实验的数据单位换算程序，大家可将换算后的程序放进 "heu-icicles\\大学物理实验\\实验表格模板\\10分光计(简化版).xlsx" 进行计算。
"""


def dms_to_degrees(degrees, minutes):
    return degrees + minutes / 60


def degrees_to_dms(degrees):
    d = int(degrees)
    m = (degrees - d) * 60
    return d, round(m)


while True:
    conversion_type = input("请选择转换类型（1：度分转度，2：度转度分）：")

    if conversion_type == "1":
        degrees_d = int(input("请输入度分数据的度部分："))
        minutes_d = int(input("请输入度分数据的分部分："))
        result = dms_to_degrees(degrees_d, minutes_d)
        print(f"{degrees_d}度 {minutes_d}分 = {result}度")
    elif conversion_type == "2":
        degrees_input = float(input("请输入以度为单位的数据："))
        d, m = degrees_to_dms(degrees_input)
        print(f"{degrees_input}度 = {d}度 {m}分")
    else:
        print("无效的选择，请输入 1 或 2。")
