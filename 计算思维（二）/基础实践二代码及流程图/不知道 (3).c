#include <stdio.h>

int main()
{
    int counts[10]; // 用于存储0-9数字的个数
    int i;

    // 读取输入数字的个数
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &counts[i]);
    }

    // 寻找能够组成的最小数并输出
    int started = 0; // 标记第一个非0数字已经输出
    for (i = 1; i < 10; i++)
    {
        if (counts[i] > 0)
        {
            printf("%d", i);
            counts[i]--;
            started = 1;
            break;
        }
    }

    for (i = 0; i < 10; i++)
    {
        while (counts[i] > 0)
        {
            printf("%d", i);
            counts[i]--;
        }
    }

    printf("\n");

    return 0;
}