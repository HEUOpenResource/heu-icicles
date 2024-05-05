#include <stdio.h>
float discount(float cost)
{
    if (cost <= 500)
        return cost;
    else if (cost > 500 && cost <= 1000)
        return cost * 0.9;
    else
        return cost * 0.8;
}

int main(void)
{
    float cost;
    scanf("%f", &cost);
    printf("%.2f", discount(cost));
    return 0;
}