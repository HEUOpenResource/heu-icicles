#include <stdio.h>

float eCost(int e)
{
    if (e <= 100 / 0.8)
        return 100;
    else if (e <= 200)
        return e * 0.8;
    else if (e <= 300)
        return 200 * 0.8 + (e - 200) * 0.9;
    else
        return 200 * 0.8 + 100 * 0.9 + (e - 300) * 1.0;
}

int main(void)
{
    int e;
    float cost;
    scanf("%d", &e);
    cost = eCost(e);
    if (cost >= 400)
        cost *= 1.15;
    printf("%.2f", cost);
    return 0;
}