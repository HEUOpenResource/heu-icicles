/*
@Filename:  ex701.c
@Author:  Ju  Chengdong but now Fuxuan
@Version:  1.0
@Date:  2021-03-18
@Description:  Salary  Management  System
*/

#include <stdio.h>
#include <string.h>

typedef struct teacher
{
    int id;         //  职工号
    char name[100]; //  姓名
    int salary;     //  工资

} teacher;

const int NUM = 5;

int main()
{
    void input(teacher * t, int n);
    void output(teacher * t, int n);
    void sort(teacher * t, int n);

    teacher t[NUM]; // 教师数组
    teacher *pt = t;

    input(pt, NUM); // 为教师数组元素赋值

    printf("Before  sorting:\n");
    output(pt, NUM); // 排序前输出

    sort(pt, NUM); // 按工资排序

    printf("After  sorting:\n");
    output(pt, NUM); // 排序后输出

    return 0;
}

/*
 *  函数名称：input
 *  函数功能：实现教师信息的键盘输入
 *  输入格式：每行输入一个教师的信息，一个教师的各个数据之间用空格分隔；
 *                      教师姓名不能包含空格
 *  形式参数：t,  struct  teacher型指针，教师数组首地址
 *  形式参数：n,  int型，教师数组元素个数
 *  返  回  值：无
 */
void input(teacher *t, int n)
{
    //  请编程实现本函数
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d", &t[i].id, t[i].name, &t[i].salary);
        // printf("\n");
    }
}

/*
 *  函数名称：output
 *  函数功能：输出教师信息
 *  输出格式：每行只输出一个教师的信息，各信息数据以逗号分隔
 *  形式参数：t,  struct  teacher型指针，教师数组首地址
 *  形式参数：n,  int型，教师数组元素个数
 *  返  回  值：无
 */
void output(teacher *t, int n)
{
    //  请编程实现本函数
    for (int i = 0; i < n; i++)
    {
        printf("%d,%s,%d\n", t[i].id, t[i].name, t[i].salary);
    }
}

/*
 *  函数名称：sort
 *  函数功能：对教师数组元素按工资由小到大进行排序
 *  形式参数：t,  struct  teacher型指针，教师数组首地址
 *  形式参数：n,  int型，教师数组元素个数
 *  返  回  值：无
 */
void sort(teacher *t, int n)
{
    //  请编程实现本函数
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (t[j].salary > t[j + 1].salary)
            {
                teacher temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}