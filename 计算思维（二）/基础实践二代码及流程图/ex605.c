/*
@Filename:  ex605.c
@Author:    Fuxuan
@Version:  1.0
@Date:  2021-03-18
@Description:  Loopy  Moving  of  Array  Element
*/
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10
/*主函数*/
int main(void)
{
    /*声明函数*/
    void input(int *p, int n);
    void output(int *p, int n);
    void move(int *p, int length, int m);

    /*定义数据结构*/
    int a[LENGTH], m; // m表示数组元素循环移动的位置个数
    int *p = a;

    /*调用input函数，通过键盘输入为数组a赋值*/
    input(p, LENGTH);

    /*从键盘输入为循环移动位置个数m赋值*/
    scanf("%d", &m);
    /*调用move函数，完成数组元素的循环移动*/
    move(p, LENGTH, m);

    /*调用output函数，输出移动后的数组元素*/
    output(p, LENGTH);
    return 0;
}
/*
 *  函数名称：input
 *  函数功能：通过键盘输入为一维数组元素赋值
 *  输入格式：各输入数据之间以空格分隔
 *  形式参数：p，int型指针变量，一维整型数组首地址
 *  形式参数：n，int型，一维数组长度
 *  返回值：无
 */
void input(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }
    //  请编程实现本函数=
}
/*
 *  函数名称：output
 *  函数功能：向屏幕打印输出一维数组元素值
 *  输出格式：各输出数据之间以空格分隔
 *  形式参数：p，int型指针变量，一维整型数组首地址
 *  形式参数：n，int型，一维数组长度
 *  返回值：无
 */
void output(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
    //  请编程实现本函数
}

/*
 *  函数名称：moveToRight
 *  函数功能：使一维数组各元素向右循环移动m个位置
 *  形式参数：p，int型指针变量，一维整型数组首地址
 *  形式参数：length，int型，一维数组长度
 *  形式参数：m，int型，循环移动的位置数
 *  返  回  值：无
 */
void moveToRight(int *p, int length, int m)
{
    // 创建临时数组
    int temp[length];

    // 将元素移动至临时数组
    for (int i = 0; i < length; i++)
    {
        temp[(i + m) % length] = *(p + i);
    }

    // 将临时数组中的元素复制回原数组
    for (int i = 0; i < length; i++)
    {
        *(p + i) = temp[i];
    }
    //  请编程实现本函数
}

/*
 *  函数名称：moveToLeft
 *  函数功能：使一维数组各元素向左循环移动m个位置
 *  形式参数：p，int型指针变量，一维整型数组首地址
 *  形式参数：length，int型，一维数组长度
 *  形式参数：m，int型，循环移动的位置数
 *  返  回  值：无
 */
void moveToLeft(int *p, int length, int m)
{
    // 创建临时数组
    int temp[length];

    m = -m;
    // 将元素移动至临时数组
    for (int i = 0; i < length; i++)
    {
        temp[(i - m + length) % length] = *(p + i);
    }
    // 将临时数组中的元素复制回原数组
    for (int i = 0; i < length; i++)
    {
        *(p + i) = temp[i];
    }
    //  请编程实现本函数
}

/*
 *  函数名称：move
 *  函数功能：使一维数组元素循环向左或向右移动m个位置
 *  形式参数：p，int型指针变量，一维整型数组首地址
 *  形式参数：length，int型，一维数组长度
 *  形式参数：m，int型，表示循环移动的方向和移动的位置个数
 *                    当m>0时，执行向右循环移动（水平方向从左向右循环移动）
 *                    当m=0时，不做任何移动
 *                    当m<0时，执行向左循环移动（水平方向从右向左循环移动）
 *  返  回  值：无
 */
void move(int *p, int length, int m)
{
    if (m > 0)
    {
        /*向右循环移动*/
        moveToRight(p, length, m);
    }
    else if (m == 0)
    {
        /*不移动*/
        ; // 空语句，什么都不做
    }
    else
    {
        /*向左循环移动*/
        moveToLeft(p, length, m);
    }
}