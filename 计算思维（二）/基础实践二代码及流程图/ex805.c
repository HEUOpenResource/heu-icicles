/*
@Filename:  ex805.c
@Author:  Ju  Chengdong
@Version:  1.0
@Date:  2021-03-18
@Description:  Data  File  Processing
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SNO_LENGTH 10
#define NAME_LENGTH 20
#define COURSE_NUMBER 3
#define STU_NUMBER 3

/*
 *  定义结构体类型student
 */
typedef struct student
{
    char sno[SNO_LENGTH];     // 学号
    char name[NAME_LENGTH];   // 姓名
    int score[COURSE_NUMBER]; // 课程成绩数组
    float average;            // 所有课程的平均成绩
} STU;

int main()
{
    /*声明函数*/
    void input(struct student * p, int rows);
    void output(STU * p, int rows);
    int writeFile(STU * p, int rows, char filename[], char mode[]);
    int readFile(STU * p, int rows, char filename[], char mode[]);

    /*定义student型结构体数组*/
    STU stu[STU_NUMBER], stu2[STU_NUMBER];

    /*从标准输入为stu数组元素赋值*/
    input(stu, STU_NUMBER);

    /*将stu数组元素值写入二进制文件，并输出成功写入的数据块个数*/
    printf("%d\n", writeFile(stu, STU_NUMBER, "ex805.dat", "wb"));
    // writeFile(stu,  STU_NUMBER,  "ex805.dat",  "wb");

    /*读取二进制文件并填充stu2数组中，并输出成功读取的数据块个数*/
    printf("%d\n", readFile(stu2, STU_NUMBER, "ex805.dat", "rb"));

    /*输出显示stu2数组元素*/
    output(stu2, STU_NUMBER);
    return 0;
}

/*
 *  函数名称：input
 *  函数功能：为形参  p  所指向的结构体数组元素以键盘输入方式进行赋值
 *  输入格式：所有学生的所有数据均需分行输入，即：
 *                      每个学生均有  5  行输入，自上而下分别为学号、姓名、三门课程成绩，
 *                      其中，学号和姓名不能包含空格
 *  形式参数：struct  student型指针，p  指向结构体数组首地址
 *  形式参数：int型，rows  为结构体数组元素个数
 *  返  回  值：无
 */
void input(struct student *p, int rows)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        // printf("\nInput  the  information  of  student  %d:\n",  (i  +  1));
        // 输入学号
        // printf("sno:\t");
        scanf("%s", (p + i)->sno);
        // gets((p  +  i)  ->  sno);
        // fgets((p  +  i)  ->  sno,  SNO_LENGTH,  stdin);
        fflush(stdin);

        // 输入姓名
        // printf("name:\t");
        scanf("%s", (p + i)->name);
        // gets((p  +  i)  ->  name);
        // fgets((p  +  i)  ->  name,  NAME_LENGTH,  stdin);
        fflush(stdin);

        // 输入三门课程成绩，并求和
        float sum = 0;
        for (j = 0; j < COURSE_NUMBER; j++)
        {
            // printf("score%d:\t",  j  +  1);
            scanf("%d", &((p + i)->score[j]));
            fflush(stdin);
            sum += (p + i)->score[j];
        }
        // 计算平均成绩
        (p + i)->average = sum / COURSE_NUMBER;
    }
}

/*
 *  函数名称：output
 *  函数功能：将形参  p  所指向的结构体数组输出到屏幕
 *  输出格式：所有同学的信息均需分行输出，即：每行只输出一个同学的所有数据，
 *                      从左至右分别为学号、姓名、三门课程成绩和平均成绩，
 *                      其中，平均成绩保留小数点后两位
 *  形式参数：struct  student型指针，p  指向结构体数组首地址
 *  形式参数：int型，rows  为结构体数组元素个数
 *  返  回  值：无
 */
void output(STU *p, int rows)
{
    int i, j;
    // printf("\nThe  students'information  is  as  follows:");
    for (i = 0; i < rows; i++)
    {
        printf("%s,", (p + i)->sno);
        // puts((p  +  i)  ->  sno);
        fflush(stdout);

        printf("%s,", (p + i)->name);
        // puts((p  +  i)  ->  name);
        fflush(stdout);

        for (j = 0; j < COURSE_NUMBER; j++)
        {
            printf("%d,", (p + i)->score[j]);
            fflush(stdout);
        }
        printf("%.2f\n", (p + i)->average);
    }
}

/*
 *  函数名称：writeFile
 *  函数功能：将指针  p  所指向的数组的所有元素值写入到二进制文件中
 *  形式参数：struct  student型指针，p  指向结构体数组的首地址
 *  形式参数：int型，rows  为结构体数组长度
 *  形式参数：一维字符数组，filename  为二进制文件路径及名称
 *  形式参数：一维字符数组，mode  为文件打开模式
 *  返  回  值：int型，若打开文件失败，返回  -1；否则，返回成功写入到文件的数据块个数
 */
int writeFile(STU *p, int rows, char filename[], char mode[])
{
    //  请编程实现本函数

    FILE *fp;
    int success_blocks = 0;

    fp = fopen(filename, mode);
    if (fp == NULL)
    {
        return -1; 
    }

    success_blocks = fwrite(p, sizeof(STU), rows, fp);

    fclose(fp);
    return success_blocks;
}

/*
 *  函数名称：readFile
 *  函数功能：读取二进制文件并存储到指针p所指向的数组
 *  形式参数：struct  student型指针，p  指向结构体数组的首地址
 *  形式参数：int型，rows  为结构体数组长度
 *  形式参数：一维字符数组，filename  为二进制文件路径及名称
 *  形式参数：一维字符数组，mode  为文件打开模式
 *  返  回  值：int型，若打开文件失败，返回  -1；否则，返回从文件成功读取的数据块个数
 */
int readFile(STU *p, int rows, char filename[], char mode[])
{
    //  请编程实现本函数

    FILE *fp;
    int success_blocks = 0;

    fp = fopen(filename, mode);
    if (fp == NULL)
    {
        return -1; 
    }

    success_blocks = fread(p, sizeof(STU), rows, fp);

    fclose(fp);
    return success_blocks;
}