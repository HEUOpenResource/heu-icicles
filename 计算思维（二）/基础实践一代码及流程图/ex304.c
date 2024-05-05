#include <stdio.h>
#include <string.h>

int getPerfect(int num)
{
    int sum = 0;
    // 判断num的因子并累加
    for (int j = 1; j < num; j++)
    {
        if (num % j == 0)
        {
            sum += j;
            // divisor[index++]=i;
        }
    }
    if (sum == num)
    {
        return sum;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int m, n, step, result, count = 0;
    int error;

    error = scanf("%d,%d", &m, &n); // error为输入的变量个数，判断用户是否少输入

    // 判断输入是否合法
    if (error != 2 || m < 0 || n < 0 || m > 9999 || n > 9999)
    {
        printf("error");
        // fflush(stdin);//注：这个是清空缓冲区的
    }
    else
    {
        // 判断m和n的大小，保证m<=n
        if (m > n)
        {
            step = m;
            m = n;
            n = step;
        }
        // 遍历m到n之间的整数，并判断是否为完数
        for (int i = m; i <= n; i++)
        {
            result = getPerfect(i);
            if (result != 0)
            {
                count++;
                // 数字间用逗号分隔
                if (count == 1)
                {
                    printf("%d", result);
                }
                else
                {
                    printf(",%d", result);
                }
            }
        }
    }
    return 0;
}