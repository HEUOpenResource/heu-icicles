/*
@Filename:  ex606.c
@Author:  Ju  Chengdong but now Fuxuan
@Version:  1.0
@Date:  2021-03-18
@Description:  Joseph  Circle  Problem
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    void inputArr(int *p, int length);
    void printArr(int *p, int length);
    int *JosephCircle(int *p, int length);

    int n; // 围成一圈的人数
    scanf("%d", &n);

    // 动态申请n个int型的内存单元
    int *arr = (int *)calloc(n, sizeof(int));
    int *p = arr;

    inputArr(p, n);                    // 为动态数组元素赋值
    printArr(p, n);                    // 输出动态数组元素值
    printf("%d", *JosephCircle(p, n)); // 输出约瑟夫环问题解

    free(arr); // 释放动态数组
    arr = NULL;

    return 1;
}

/*
 *  函数名称：inputArr
 *  函数功能：为一维整型数组元素赋值。赋值规则：对于包含n个元素的数组，
 *                      则从第1个数组元素开始，依次分别赋值为1、2、3  ...  n-1、n
 *  形式参数：p，int型指针变量，一维整型数组首地址
 *  形式参数：length，int型，一维数组长度
 *  返回值：无
 */
void inputArr(int *p, int length)
{
    for (int i = 0; i < length; i++)
    {
        *(p + i) = i + 1;
    }

    //  请编程实现本函数
}

/*
 *  函数名称：printArr
 *  函数功能：输出一维数组元素值。输出规则：每行输出10个元素值，每个值至少占4位位宽；
 *                      每行除了最后一个值外，其他元素值之间以逗号分隔
 *  形式参数：p，int型指针变量，一维整型数组首地址
 *  形式参数：length，int型，一维数组长度
 *  返回值：无
 */
void printArr(int *p, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            printf("%4d", *(p + i));
        }
        else if (i % 10 == 0)
        {
            printf("\n");
            printf("%4d", *(p + i));
        }
        else
        {
            printf(",%4d", *(p + i));
        }
    }
    printf("%c", '\n');

    //  请编程实现本函数
}

/*
 *  函数名称：JosephCircle
 *  函数功能：求解约瑟夫环问题
 *  形式参数：p，int型指针变量，一维整型数组首地址
 *  形式参数：length，int型，一维数组长度
 *  返回值：int型指针，为最后留下来的那个人的编号（整型变量）的内存单元地址
 */
int *JosephCircle(int *p, int length)
{
    int k, r = 0;
    for (int i = 2; i <= length; i++)
    {
        k = (3 % i);     // 偏移量
        r = (r + k) % i; // 更新最后留下来的人的编号
    }
    return p + r;
    //  请编程实现本函数
}