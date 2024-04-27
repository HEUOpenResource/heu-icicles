#include <stdio.h>

void movingBricks(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k += 2) // 小孩必须为偶数
            {
                if (i + j + k == n && 4 * i + 3 * j + k / 2 == n)
                {
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);

    movingBricks(n);

    return 0;
}