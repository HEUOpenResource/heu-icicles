#include <stdio.h>

int sim(int front, int end)
{
    // 辗转相除法求最大公约数
    int temp;
    while (end)
    {
        temp = end;
        end = front % end;
        front = temp;
    }
    return front;
}

int main(void)
{
    int front, end, n;
    scanf("%d %d", &front, &end);

    n = sim(front, end);
    front /= n;
    end /= n;

    printf("%d %d", front, end);

    return 0;
}