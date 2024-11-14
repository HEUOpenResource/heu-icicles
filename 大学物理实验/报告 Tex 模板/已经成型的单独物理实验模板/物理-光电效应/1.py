import numpy as np


x = np.array([7.5, 6.52, 5.77, 5.08, 4.98, 4.8])
y = np.array([1.658, 1.31675, 0.953, 0.6885, 0.605, 0.53075])

n = len(x)

numerator = np.sum(x * y) - (1 / n) * np.sum(x) * np.sum(y)
denominator = np.sum(x**2) - (1 / n) * np.sum(x) ** 2
k = numerator / denominator

print("k = ", k)
