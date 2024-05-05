#include <stdio.h>

double all_balance(double a, double b, int mouth)
{
    double sum = 0, fuxuan = a;
    for (int i = 1; i <= mouth; i++)
    {
        sum = (1 + b / 12) * a;
        a = sum + fuxuan;
    }
    return sum;
}

int main(void)
{
    int mouth;
    double balance, rate;
    scanf("%lf,%lf,%d", &balance, &rate, &mouth);
    printf("%.2lf", all_balance(balance, rate, mouth));
    return 0;
}

// 递归方法失败了
//  double balance(double b, double e, double r, double m)
//  {
//      if (m == 0)
//      {
//          return b;
//      }

//     if (m == 1)
//     {
//         return balance(b, e, r, m - 1) + b * r;
//     }
//     else
//     {
//         return balance(b + e, e, r, m - 1) + b * r;
//     }
// }

// int main(void)
// {
//     double monthlyBalance, rate, month, each;
//     scanf("%lf,%lf,%lf", &monthlyBalance, &rate, &month);
//     each = monthlyBalance;
//     rate /= 12;

//     printf("%.3lf", balance(monthlyBalance, each, rate, month));

//     return 0;
// }

// 主函数方法
//  int main(void)
//  {
//      int mouth, i;
//      double a, b, sum;
//      scanf("%lf,%lf,%d", &a, &b, &mouth);
//      int fu = a;
//      for (i = 1; i <= mouth; i++)
//      {
//          sum = (1 + b / 12) * a;
//          a = sum + fu;
//      }
//      printf("%.2lf", sum);
//      return 0;
//  }
