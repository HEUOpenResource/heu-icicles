#include <stdio.h>
int main(void)
{
    int a, b, c, d;
    scanf("%d,%d,%d,%d", &a, &b, &c, &d);
    if (a > b)
        a = b;
    if (c < d)
        c = d;
    printf("%d", a + c);
    return 0;
}