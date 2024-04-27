#include <stdio.h>

int main(void)
{
    int a, sum = 0;
    scanf("%d", &a);
    if (a >= 3 && a <= 10)
    {
        for (int i = 1; i <= 6; i++)
        {
            sum += a * a * a * a;
            a += 3;
        }
        printf("%d", sum);
    }
    else
    {
        printf("error");
    }
    return 0;
}