#include <stdio.h>

int narcissistic(int num)
{
    int hundred, decade, unit;

    // 分别取出个位、十位、百位
    hundred = num / 100;
    decade = (num / 10) % 10;
    unit = num % 10;

    if (num == hundred * hundred * hundred + decade * decade * decade + unit * unit * unit)
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
    for (int i = 100; i < 1000; i++)
    {
        if (narcissistic(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}