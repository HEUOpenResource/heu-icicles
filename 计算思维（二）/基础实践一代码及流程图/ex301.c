#include <stdio.h>

int main(void)
{
    int num, sum = 0;
    for (int i = 0; i < 8; i++)
    {
        num = 0;
        scanf("%d", &num);
        if (num % 2 == 0)
        {
            sum += num;
        }
        }
    printf("%d", sum);
}

// 遍历数组的方法：
//  int main(void)
//  {
//      int list[10], sum = 0;
//      for (int i = 0; i < 8; i++)
//      {
//          scanf("%d", &list[i]);
//          if (list[i] % 2 == 0)
//          {
//              sum += list[i];
//          }
//      }
//      printf("%d", sum);
//  }