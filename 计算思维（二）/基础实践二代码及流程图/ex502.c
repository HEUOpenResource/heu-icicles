#include <stdio.h>
#include <string.h>

void delRepeat(char *s1, char *s2)
{
    char newStr[255] = {'\0'}; // 字符串初始化为 \0
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int count = 0;
    int boolen;

    for (int i = 0; i < len1; i++)
    {
        boolen = 0;
        for (int j = 0; j < len2; j++)
        {
            if (s1[i] == s2[j])
            {
                boolen = 1;
                break;
            }
        }
        if (!boolen)
        {

            newStr[count] = s1[i];
            count++;
        }
    }
    printf("%s", newStr);
}

int main(void)
{
    char s1[255];
    char s2[255];

    fgets(s1, 255, stdin);
    fgets(s2, 255, stdin);

    // 去除换行符
    s1[strlen(s1) - 1] = '\0';
    s2[strlen(s2) - 1] = '\0';

    delRepeat(s1, s2);

    return 0;
}