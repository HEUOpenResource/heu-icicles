#include <stdio.h>

int re_order(int num)
{
    // 取逆序数
    int front = num;
    int back;
    int new = 0;

    do
    {
        back = front % 10;
        front = front / 10;
        new = back + new * 10;
    } while (front > 0);

    return new;
}

int main(void)
{
    int num_1, num_2;
    int new_1, new_2;
    scanf("%d %d", &num_1, &num_2);

    new_1 = re_order(num_1);
    new_2 = re_order(num_2);
    if (num_1 * num_2 == new_1 * new_2)
    {
        printf("%d*%d=%d*%d", num_1, num_2, new_1, new_2);
    }
    else
    {
        printf("%d*%d!=%d*%d", num_1, num_2, new_1, new_2);
    }

    return 0;
}