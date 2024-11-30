"""
请将原始数据先填入 12迈克尔孙干涉仪实验.xlsx 表格中，获取 lambda_overline 和 delta_d300_mm 的数据。

    lambda_overline 是表格的 lambda_bar_SI, 单位 mm;

    delta_d300_mm 是表格中的 delta_d300 数据。
"""

# =============================数据代入区 ==============================
lambda_overline = 6.393e-4  # 单位 mm # 表格的 λ 平均值，单位 mm
delta_d300_mm = [0.09610, 0.09590, 0.09620, 0.10587, 0.08589, 0.09542]  # Δd300/mm
# ============================ 数据代入区结束 ===========================

# 常量设置
delta_instrument = 0.00005  # 单位 mm  Δd0
# λ_标
lambda_standard = 6.328e-7  # 单位 m

# 计算 S
n = len(delta_d300_mm)
mean_delta_d300 = sum(delta_d300_mm) / n
S = (sum((mean_delta_d300 - d) ** 2 for d in delta_d300_mm) / (n - 1)) ** 0.5

# 计算 ΔB
delta_B = (2 * delta_instrument**2) ** 0.5

# 计算 Δλ
delta_lambda = (2 / 300) * (S**2 + delta_B**2) ** 0.5

# 计算 λ，单位转换为米
lambda_overline *= 1e-3  # 转换为 m
delta_lambda *= 1e-3  # 转换为 m


# 计算 Er
E_r = abs(lambda_standard - lambda_overline) / lambda_standard * 100

# 输出结果
print(f"λ_mean = {lambda_overline:.3e} m")
print(f"S = {S:.3e} mm")
print(f"Δλ = {delta_lambda:.3e} m")
print(f"λ = {lambda_overline:.3e} +/- {delta_lambda:.3e} m")
print(f"E_r = {E_r:.2f}%")
