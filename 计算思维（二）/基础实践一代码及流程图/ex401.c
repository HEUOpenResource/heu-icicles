#include <stdio.h>

float sum(float up, float down, int n)
{
    float temp;
    float result = 0.00;
    for (int i = 0; i < n; i++)
    {
        result += (up * 1.0 / down); // 前n项和的结果

        // 创造下一个项
        temp = up;
        up = up + down;
        down = temp; // 之前竟然写错成down=up了。
    }

    return result;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%.2f", sum(2.00, 1.00, n));
    return 0;
}
