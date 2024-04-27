#include <stdio.h>

void dectobin(int n);

void dectobin(int n)
{
    if (n > 1)
    {
        dectobin(n / 2);
        printf("%d", n % 2); // 输出n的二进制表示，从最高位开始
    }
    else
        printf("%d", n);
}

int main()
{
    int n;

    scanf("%d", &n);
    dectobin(n);

    return 0;
}