/*
@Filename:  ex804.c
@Author:  Ju  Chengdong
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
    void readFileForStu(struct stu * p, int num, char filename[], char mode[]);
    void stdoutForStu(struct stu * p, int num);
    const int NUM = 2;             // 学生数量
    struct stu students[NUM];      // stu型数组
    struct stu *p = students;      // stu型指针
    char filename[] = "ex804.txt"; // 待读取的文件路径及名称

    /*从文件获取输入*/
    readFileForStu(p, NUM, filename, "r");

    /*向屏幕输出显示*/
    stdoutForStu(p, NUM);
    return 0;
}

/*
 *  函数名称：readFileForStu
 *  函数功能：从文件格式化读取数据
 *  写入格式：共读取  num  行；每行读出一个  stu  型数据，每个成员变量之间用空格分隔
 *  形式参数：struct  stu  *  p，指向  stu  型一维数组首地址。该数组用于保存文件读取数据
 *  形式参数：int  num，一维数组元素个数，也即读取文件的行数
 *  形式参数：char  filename[]，待读取的文件路径及名称
 *  形式参数：char  mode[]，文件使用方式
 *  返  回  值：无
 */
void readFileForStu(struct stu *p, int num, char filename[], char mode[])
{
    //  请编程实现本函数

    FILE *file = fopen(filename, mode);

    for (int i = 0; i < num; i++)
    {
        fscanf(file, "%d %s %d %d", &p[i].id, p[i].name, &p[i].age, &p[i].score);
    }

    fclose(file);
}

/*
 *  函数名称：stdoutForStu
 *  函数功能：向显示器输出显示数据
 *  输出格式：共输出  num  行；每行输出一个  stu  型数据，每个成员变量之间用空格分隔
 *  形式参数：struct  stu  *  p，指向  stu  型一维数组首地址
 *  形式参数：int  num，一维数组元素个数
 *  返  回  值：无
 */
void stdoutForStu(struct stu *p, int num)
{
    //  请编程实现本函数

    for (int i = 0; i < num; i++)
    {
        printf("%d %s %d %d\n", p[i].id, p[i].name, p[i].age, p[i].score);
    }
}
