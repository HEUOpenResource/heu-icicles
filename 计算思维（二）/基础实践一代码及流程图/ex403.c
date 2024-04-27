#include <stdio.h>

int if_palin(int num)
{
    int front = num;
    int back;
    int new = 0;

    do
    {
        back = front % 10;
        front = front / 10;
        new = back + new * 10;
    } while (front > 0);

    if (new == num)
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
    int n;
    int count = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {

        if (if_palin(i))
        {
            count++;
            if (count % 10 == 0)
            {
                printf("%d,\n", i);
            }
            else
            {
                printf("%d,", i);
            }
        }
    }

    return 0;
}