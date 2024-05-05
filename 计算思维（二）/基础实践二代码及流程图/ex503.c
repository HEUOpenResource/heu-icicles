#include <stdio.h>

void Visit(int a[][400], int n)
{
    int p = n - 1, q = 0, i;
    int count = 0;

    while (count < n * n)
    {
        for (i = p; i >= q; i--)
        {
            a[q][i] = count + 1;
            count += 1;
        }

        for (i = q + 1; i <= p; i++)
        {
            a[i][q] = count + 1;
            count += 1;
        }

        for (i = q + 1; i <= p; i++)
        {
            a[p][i] = count + 1;
            count += 1;
        }

        for (i = p - 1; i >= q + 1; i--)
        {
            a[i][p] = count + 1;
            count += 1;
        }
        p--;
        q++;
    }
}

void Print(int a[][400], int n)
{
    int h, j;
    for (h = 0; h < n; h++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d ", a[h][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, a[400][400];
    scanf("%d", &n);
    Visit(a, n);
    Print(a, n);
    return 0;
}
