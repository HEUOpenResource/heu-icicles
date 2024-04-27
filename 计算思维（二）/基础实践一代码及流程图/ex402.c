#include <stdio.h>

int is_prime(int num)
// 判断num是否为质数
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int is_double(int prime)
// 判断prime是否为双质数
{
    if (is_prime(prime) && is_prime(prime + 2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int m, n;
    scanf("%d,%d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        if (is_double(i) && i + 2 <= n)
        {
            printf("%d,%d\n", i, i + 2);
        }
    }
    return 0;
}