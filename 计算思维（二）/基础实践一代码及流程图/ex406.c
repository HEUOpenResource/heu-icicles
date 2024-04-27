#include <stdio.h>

int is_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int year;
    scanf("%d", &year);

    if (is_leap(year))
    {
        printf("%d is a leap year", year);
    }
    else
    {
        printf("%d is not a leap year", year);
    }
    return 0;
}