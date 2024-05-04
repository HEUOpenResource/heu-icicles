/*
@Filename:  ex702.c
@Author: Fuxuan
@Version:  1.0
@Date:  2021-03-18
@Description:  Complex  Addition  and  Subtraction
*/

#include <stdio.h>

struct complex
{
    int re; //  real  part（实部）
    int im; //  imaginary  part（虚部）
};

int main()
{
    struct complex add(struct complex a, struct complex b);
    struct complex minus(struct complex a, struct complex b);

    struct complex x, y, z;
    //  输入实数x的实部和虚部
    scanf("%d,%d", &x.re, &x.im);
    //  输入实数y的实部和虚部
    scanf("%d,%d", &y.re, &y.im);

    //  计算并输出复数加法和
    z = add(x, y);
    printf("%d+%di\n", z.re, z.im);
    //  计算并输出复数减法差
    z = minus(x, y);
    printf("%d+%di", z.re, z.im);

    return 0;
}

/*
 *  函数名称：add
 *  函数功能：实现复数加法运算
 *  形式参数：struct  complex  a，操作数
 *  形式参数：struct  complex  b，操作数
 *  返  回  值：struct  complex型，返回形参a和形参b的加法结果
 */
struct complex add(struct complex a, struct complex b)
{
    //  请编程实现本函数
    struct complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

/*
 *  函数名称：minus
 *  函数功能：实现复数减法运算
 *  形式参数：struct  complex  a，操作数
 *  形式参数：struct  complex  b，操作数
 *  返  回  值：struct  complex型，返回形参a和形参b的减法结果
 */
struct complex minus(struct complex a, struct complex b)
{
    //  请编程实现本函数
    struct complex c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return c;
}