#include <stdio.h>

// 分离个位和十位:
int decade, unit;

void separate(int num)
{
    decade = num / 10;
    unit = num % 10;
}

// 将10~20单独处理：
char *Num10_20(int num)
{
    char *enNum;
    switch (num)
    {
    case 10:
        enNum = "ten";
        break;
    case 11:
        enNum = "eleven";
        break;
    case 12:
        enNum = "twelve";
        break;
    case 13:
        enNum = "thirteen";
        break;
    case 14:
        enNum = "fourteen";
        break;
    case 15:
        enNum = "fifteen";
        break;
    case 16:
        enNum = "sixteen";
        break;
    case 17:
        enNum = "seventeen";
        break;
    case 18:
        enNum = "eighteen";
        break;
    case 19:
        enNum = "nineteen";
        break;
    case 20:
        enNum = "twenty";
        break;
    }
    return enNum;
}

// 将十位单独处理：
char *enDecade(int decade)
{
    char *enNum_first;
    switch (decade)
    {
    case 2:
        enNum_first = "twenty";
        break;
    case 3:
        enNum_first = "thirty";
        break;
    case 4:
        enNum_first = "forty";
        break;
    case 5:
        enNum_first = "fifty";
        break;
    case 6:
        enNum_first = "sixty";
        break;
    case 7:
        enNum_first = "seventy";
        break;
    case 8:
        enNum_first = "eighty";
        break;
    case 9:
        enNum_first = "ninety";
        break;
    }
    return enNum_first;
}

// 将个位单独处理：
char *enUnit(int unit)
{
    char *enNum_last;
    switch (unit)
    {
    case 1:
        enNum_last = "one";
        break;
    case 2:
        enNum_last = "two";
        break;
    case 3:
        enNum_last = "three";
        break;
    case 4:
        enNum_last = "four";
        break;
    case 5:
        enNum_last = "five";
        break;
    case 6:
        enNum_last = "six";
        break;
    case 7:
        enNum_last = "seven";
        break;
    case 8:
        enNum_last = "eight";
        break;
    case 9:
        enNum_last = "nine";
        break;
    }
    return enNum_last;
}

int main(void)
{
    int num;
    scanf("%d", &num);
    separate(num);
    if (num >= 10 && num <= 20)
    {
        printf("%s", Num10_20(num));
    }
    else
    {
        printf("%s-%s", enDecade(decade), enUnit(unit));
    }

    return 0;
}