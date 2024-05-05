#include <stdio.h>

int main()
{
    int N, num;
    int maxNum, maxCount;
    int counts[1000] = {0};

    // 读取序列中整数的个数
    scanf("%d", &N);

    // 统计每个整数的出现次数
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        counts[num]++;
    }

    // 找到出现次数最多的整数和对应的次数
    maxNum = 0;
    maxCount = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (counts[i] > maxCount)
        {
            maxNum = i;
            maxCount = counts[i];
        }
    }

    // 输出结果
    printf("%d %d\n", maxNum, maxCount);

    return 0;
}