#include <stdio.h>

/*
@Filename:  ex604.c
@Author:  Fuxuan
@Version:  1.0
@Date:  2021-03-18
@Description:  Number  to  Month
*/

/*
 *  函数名称：hundredsDigit
 *  函数功能：获取形参整数位于百位上的数字
 *  形式参数：num，一个整型数
 *  返  回  值：返回形参整数位于百位上的数字
 */
static int hundredsDigit(int num)
{
    return num / 100;
    //  请编程实现本函数
}

/*
 *  函数名称：tensDigit
 *  函数功能：获取形参整数位于十位上的数字
 *  形式参数：num，一个整型数
 *  返  回  值：返回形参整数位于十位上的数字
 */
static int tensDigit(int num)
{
    return (num % 100) / 10;
    //  请编程实现本函数
}

/*
 *  函数名称：unitsDigit
 *  函数功能：获取形参整数位于个位上的数字
 *  形式参数：num，一个整型数
 *  返  回  值：返回形参整数位于个位上的数字
 */
static int unitsDigit(int num)
{
    return num % 10;
    //  请编程实现本函数
}

/*
 *  函数名称：searchMonth
 *  函数功能：对num进行判断，若1≤num≤12，返回month[num]；否则返回month[0]
 *  形式参数：month，为表示月份单词的字符指针数组
 *                      num，为一个整数
 *  返  回  值：字符指针，为月份单词的首地址
 */
static char *searchMonth(char *month[], int num)
{
    return (num >= 1 && num <= 12) ? month[num] : month[0];
    //  请编程实现本函数
}

/*
 *  函数名称：getNumber
 *  函数功能：从键盘输入一个三位正整数，若不符合要求，则重新输入
 *  形式参数：无
 *  返  回  值：返回所输入的三位正整数
 */
int getNumber()
{
    int num;
    scanf("%d", &num);
    if (num >= 100 && num <= 999)
    {
        return num;
    }
    else
    {
        return getNumber();
    }

    //  请编程实现本函数
}

/*
 *  函数名称：bizProcess
 *  函数功能：业务处理函数，功能定义如下。
 *    （1）调用hundredsDigit等函数，对一个三位数的各位进行拆分并计算数字和
 *    （2）调用searchMonth函数，对上述数字和进行检索返回其月份单词
 *    （3）按题目要求的格式，打印输出上述结果
 *  形式参数：month，为一个指针数组，指向月份单词的字串数组
 *                      num，一个整数
 *  返  回  值：无
 */
void bizProcess(char *month[], int num)
{
    int unitsD, tensD, hundredsD, sum;
    unitsD = unitsDigit(num);
    tensD = tensDigit(num);
    hundredsD = hundredsDigit(num);
    sum = unitsD + tensD + hundredsD;

    printf("%s", searchMonth(month, sum));
}

int main(void)
{
    /*定义数据结构*/
    char *month[] =
        {
            "***",
            "January", "February", "March",
            "April", "May", "June",
            "July", "August", "September",
            "October", "November", "December"};
    /*获取一个三位正整数*/
    int number = getNumber();
    /*业务逻辑判断处理*/
    bizProcess(month, number);

    return 1;
}