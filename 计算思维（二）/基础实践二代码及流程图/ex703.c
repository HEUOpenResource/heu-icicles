/*
@Filename:  ex703.c
@Author:  Ju  Chengdong but now Fuxuan
@Version:  1.0
@Date:  2021-03-18
@Description:  Simple  Library  Management  Program
*/

#include <stdio.h>
#include <string.h>

typedef struct book
{
    int id;          //  书号
    char name[30];   //  书名
    char author[30]; // 作者
    float price;     // 价格
} BOOK;

int main()
{
    /*  声明函数  */
    void input(struct book * p, int num);
    void output(struct book * p, int num);
    struct book *findBookByID(struct book * p, int num, int id);
    struct book *findBookByName(struct book * p, int num, char name[]);

    /*  声明变量  */
    const int NUM = 3;
    struct book myBooks[NUM];
    struct book *pBook = myBooks;
    BOOK *theBook;

    /*  为myBooks数组的所有元素赋值  */
    input(pBook, NUM);

    /*  按ID检索图书  */
    int bookID;
    scanf("%d", &bookID);
    fflush(stdin);                              /*清空输入缓冲区*/
    theBook = findBookByID(pBook, NUM, bookID); /*按书号检索*/
    output(theBook, 1);                         /*输出检索结果*/

    /*  输出myBooks数组的所有元素值  */
    output(pBook, NUM);

    return 0;
}

/*
 *  函数名称：input
 *  函数功能：从键盘输入为book型结构体数组元素赋值
 *  输入格式：（1）共输入num本图书信息
 *                      （2）对每本图书，在一行内分别输入书号、书名、作者、价格，各数据之间以空格分隔
 *                      （3）书名和作者不能包含空格
 *  形式参数：p，book型指针，book型一维数组首地址
 *  形式参数：num，int型，图书数量
 *  返  回  值：无
 */
void input(struct book *p, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        scanf("%d  %s  %s  %f", &(p + i)->id, (p + i)->name, (p + i)->author, &(p + i)->price);
    }
}

/*
 *  函数名称：output
 *  函数功能：输出显示book型结构体数组元素值
 *  输出格式：（1）一行输出一本图书信息，共输出num行
 *                      （2）每行先后输出书号、书名、作者、价格（保留小数点后2位），用逗号分隔图书信息
 *                      （3）若形参p为空指针，则输出字串NULL
 *  形式参数：p，book型指针，book型一维数组首地址
 *  形式参数：num，int型，图书数量
 *  返  回  值：无
 */
void output(struct book *p, int num)
{
    //  请编程实现本函数
    if (p == NULL)
    {
        printf("NULL\n");
        return;
    }
    for (int i = 0; i < num; i++)
    {
        printf("%d,%s,%s,%.2f\n", (p + i)->id, (p + i)->name, (p + i)->author, (p + i)->price);
    }
}

/*
 *  函数名称：findBookByID
 *  函数功能：按书号检索图书
 *  形式参数：p，book型指针，book型一维数组首地址
 *  形式参数：num，int型，图书数量
 *  形式参数：id，int型，书号
 *  返  回  值：返回 book 型指针。若没有找到图书，则返回空指针NULL；否则，仅返回第1本符合检索条件的图书
 */
struct book *findBookByID(struct book *p, int num, int id)
{
    //  请编程实现本函数
    struct book *theBook = NULL;

    for (int i = 0; i < num; i++)
    {
        if ((p + i)->id == id)
            -- --
            {
                theBook = p + i;
                break; // 找到后退出循环
            }
    }

    return theBook;
}

/*
 *  函数名称：findBookByName
 *  函数功能：按书名检索图书
 *  形式参数：p，book型指针，book型一维数组首地址
 *  形式参数：num，int型，图书数量
 *  形式参数：name，字符数组，书名
 *  返  回  值：返回book型指针。若没有找到图书，则返回空指针NULL；否则，仅返回第1本符合检索条件的图书
 */
struct book *findBookByName(struct book *p, int num, char name[])
{
    struct book *theBook = NULL;
    if (p == NULL)
    {
        return theBook;
    }
    int i;
    for (i = 0; i < num; i++)
    {
        if (strcmp((p + i)->name, name) == 0)
        {
            theBook = p + i;
            break; // 检索到第一个符合条件的图书后就强制退出
        }
    }
    return theBook;
}