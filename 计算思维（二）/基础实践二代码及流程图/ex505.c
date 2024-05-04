#include <stdio.h>

int main(void)
{
    int a[10];
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
        if (i < 9)
        {
            sum += a[i];
        }
    }
    a[9] = sum / 9;

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            printf("%d", a[i]);
        }
        else
        {
            printf(",%d", a[i]);
        }
    }
    return 0;
}