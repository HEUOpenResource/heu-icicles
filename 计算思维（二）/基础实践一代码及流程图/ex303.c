#include <stdio.h>

float eat(float peach, int i)
{

    if (i < 10)
        return eat((peach + 1) * 2, ++i);
    else
        return peach;
}

int main()
{
    printf("%.f", eat(1, 1));
    return 0;
}