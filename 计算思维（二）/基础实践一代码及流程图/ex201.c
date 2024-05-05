#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    if (num % 2 == 0 || num < 0)
        printf("%d", num * num);
    else
        printf("%d", num / 2);

    return 0;
}