#include <stdio.h>

int outNumber(int num)
{
    printf("%d,", num);
    int count = 0;
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        // 求num的所有因子
        if (num % i == 0)
        {
            count++;
            sum += i;
            if (count == 1)
            {
                printf("%d", i);
            }
            else
            {
                printf("+%d", i);
            }
        }
    }
    printf("=%d", sum);
    return sum;
}

int main(void)
{
    int a, b;
    int result_1, result_2;
    scanf("%d %d", &a, &b);

    result_1 = outNumber(a);
    printf("\n");
    result_2 = outNumber(b);
    printf("\n");

    if (a == result_2 && b == result_1)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }

    return 0;
}