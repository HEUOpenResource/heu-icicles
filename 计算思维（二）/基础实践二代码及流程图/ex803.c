/*
@Filename:  ex803.c
@Author:  Ju  Chengdong but now Fuxuan
@Version:  1.0
@Date:  2021-03-18
@Description:  Format  Input  and  Output
*/

#include <stdio.h>
struct stu
{
    int id;        // 学号
    char name[20]; // 姓名
    int age;       // 年龄
    int score;     // 成绩
};

int main()
{
    /*声明函数及变量*/
    void stdinForStu(struct stu * p, int num);
    void writeFileForStu(struct stu * p, int num, char filename[], char mode[]);
    const int NUM = 2;             // 学生数量
    struct stu students[NUM];      // stu型数组
    struct stu *p = students;      // stu型指针
    char filename[] = "ex803.txt"; // 待写入文件路径及名称

    /*从键盘获取输入*/
    stdinForStu(p, NUM);

    /*向文件写入数据*/
    writeFileForStu(p, NUM, filename, "w");

    return 0;
}

/*
 *  函数名称：stdinForStu
 *  函数功能：从键盘输入数据，保存到指针  p  所指向的数组中
 *  输入格式：共输入  num  行；每行输入一个  stu  型数据，每个成员变量之间用空格分隔
 *  形式参数：struct  stu  *  p，指向  stu  型一维数组首地址
 *  形式参数：int  num，一维数组元素个数
 *  返  回  值：无
 */
void stdinForStu(struct stu *p, int num)
{
    //  请编程实现本函数

    for (int i = 0; i < num; i++)
    {

        scanf("%d %s %d %d", &p[i].id, p[i].name, &p[i].age, &p[i].score);

    }
}

/*
 *  函数名称：writeFileForStu
 *  函数功能：向文件格式化写入数据
 *  写入格式：共写入  num  行；每行写入一个  stu  型数据，每个成员变量之间用空格分隔
 *  形式参数：struct  stu  *  p，指向  stu  型一维数组首地址。该数组数据将被写入文件
 *  形式参数：int  num，一维数组元素个数，也即写入到文件的行数
 *  形式参数：char  filename[]，待写入的文件路径及名称
 *  形式参数：char  mode[]，文件使用方式
 *  返  回  值：无
 */
void writeFileForStu(struct stu *p, int num, char filename[], char mode[])
{
    //  请编程实现本函数

    FILE *file = fopen(filename, mode);


    for (int i = 0; i < num; i++)
    {
        fprintf(file, "%d %s %d %d\n", p[i].id, p[i].name, p[i].age, p[i].score);
    }

    fclose(file);
}
