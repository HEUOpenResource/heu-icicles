#include <stdio.h>

float p(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
    else
    {
        return ((2.0 * n - 1) * x - p(x, n - 1) - (n - 1.0) * p(x, n - 2)) / n;
    }
}
int main(void)
{
    int n, x;
    scanf("%d,%d", &n, &x);
    if (n >= 0)
        printf("%.2f", p(x, n));
    else
        printf("error");
}