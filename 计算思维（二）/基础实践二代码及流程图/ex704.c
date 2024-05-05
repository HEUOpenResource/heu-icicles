/*
@Filename:  ex704.c
@Author:  Ju  Chengdong but now Fuxuan
@Version:  1.0
@Date:  2021-03-18
@Description:  Reverse  Single  Linked  List
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

int main()
{
    /*  声明函数  */
    struct node *createList(int codeNum);
    struct node *reverse(struct node * pHead);
    void display(struct node * pHead);

    /*  生成新链表  */
    int num;
    scanf("%d", &num);
    struct node *pHead = createList(num);

    /*  输出链表结点（反转前）  */
    printf("\n");
    display(pHead);

    /*  反转单链表*/
    pHead = reverse(pHead);

    /*  输出链表结点（反转后）  */
    printf("\n");
    display(pHead);
    return 0;
}

/*
 *  函数名称：createList
 *  函数功能：使用头插法创建单链表，创建每个结点的同时为其value字段从键盘输入赋值
 *  形式参数：int型，链表结点个数
 *  返  回  值：返回struct  node型指针，为单链表头结点
 */
struct node *createList(int codeNum)
{
    /*  声明函数  */
    struct node *createNode();
    /*  声明一个头结点  */
    struct node *pHead = NULL;
    /*
     *  生成单链表。有两种链表：空头链表和无空头链表
     *  下面创建的是无空头链表
     */
    int i;
    for (i = 1; i <= codeNum; i++)
    {
        /*  创建新结点  */
        struct node *newNode = createNode();
        /*
         *  将新结点插入链表中，常用方式有：头插法、尾插法等。
         *  头插法算法简单，但结点次序与输入数据的顺序不一致。
         *  若希望两者次序一致，可采用尾插法。
         *
         *  以下采用头插法
         */
        newNode->next = pHead; /*将newNode指向上一步的头结点*/
        pHead = newNode;       /*将newNode作为新的头结点*/
    }
    return pHead;
}

/*
 *  函数名称：createNode
 *  函数功能：创建一个新结点
 *  形式参数：无
 *  返  回  值：无
 */
struct node *createNode()
{
    //  动态申请内存，创建新结点
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode != NULL)
    {
        //  为新结点的各字段赋值
        scanf("%d", &newNode->value);
        newNode->next = NULL; //  好习惯，不要让指针处于未赋值状态
    }
    return newNode;
}

/*
 *  函数名称：display
 *  函数功能：输出单链表所有结点的value字段值
 *  输出格式：在一行内输出所有结点的value字段值，用空格分隔
 *  形式参数：struct  node型指针，为单链表头结点
 *  返  回  值：无
 */
void display(struct node *pHead)
{
    //  请编程实现本函数
    struct node *current = pHead;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
}
