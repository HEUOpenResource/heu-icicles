#include <stdio.h>

float old_cost(float a, float b, float c)
{
    return (a - b) / c;
}
float old_price(float a, float b, float c)
{
    return a - b * c;
}

int main(void)
{
    float purchase, scrap, life, year, result_1, result_2;
    scanf("%f,%f,%f,%f", &purchase, &scrap, &life, &year);

    result_1 = old_cost(purchase, scrap, life);
    result_2 = old_price(purchase, result_1, year);

    printf("%.2f,%.2f", result_1, result_2);
    return 0;
}