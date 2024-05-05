#include <stdio.h>

int main(void)
{
    int num1[5];
    int num2[5];
    int final[10];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num1[i]);
        final[i] = num1[i];
    }
    
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num2[i]);
        final[i + 5] = num2[i];
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            printf("%d", final[i]);
        }
        else
        {

            printf(",%d", final[i]);
        }
    }

    // 冒泡排序
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (final[j] > final[j + 1])
            {
                int temp = final[j];
                final[j] = final[j + 1];
                final[j + 1] = temp;
            }
        }
    }

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            printf("%d", final[i]);
        }
        else
        {
            printf(",%d", final[i]);
        }
    }

    return 0;
}