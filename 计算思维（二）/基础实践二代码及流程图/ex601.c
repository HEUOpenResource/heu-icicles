/*
@Filename:  ex601.c
@Author:    Fuxuan
@Version:  1.0
@Date:  2021-03-18
@Description:  Simple  Application  of  Pointer
*/

#include <stdio.h>

/*主函数*/
int main(void)
{
    int sum(int *a, int *b);
    int minus(int *a, int *b);
    void swap(int *a, int *b);

    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d,%d", &a, &b);

    int (*p)(int *, int *);
    p = sum;
    printf("%d", (*p)(pa, pb));
    p = minus;
    printf("\n%d", (*p)(pa, pb));

    void (*q)(int *, int *);
    q = swap;
    (*q)(pa, pb);

    printf("\n%d,%d", a, b);

    return 1;
}

/*
 *  函数名称：sum
 *  函数功能：对两个整数进行加法计算
 *  形式参数：a，整型指针
 *  形式参数：b，整型指针
 *  返  回  值：int型，为两个整数的加法和
 */
int sum(int *a, int *b)
{
    return *a + *b;
    // 请编程实现本函数
}

/*
 *  函数名称：minus
 *  函数功能：对两个整数进行减法计算
 *  形式参数：a，整型指针
 *  形式参数：b，整型指针
 *  返  回  值：int型，为两个整数的减法差
 */
int minus(int *a, int *b)
{
    return *a - *b;
    // 请编程实现本函数
}

/*
 *  函数名称：swap
 *  函数功能：交换两个整数数值
 *  形式参数：a，整型指针
 *  形式参数：b，整型指针
 *  返  回  值：无
 */
void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
    // 请编程实现本函数
}
