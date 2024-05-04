#include <stdio.h>
#include <string.h>

int getNum(char *str1, char *str2)
{
    int len_1 = strlen(str1) - 1; // 字符串长度减一，因为fgets函数也输入了换行符
    int len_2 = strlen(str2) - 1;

    if (len_1 >= len_2)
    {
        for (int i = 0; i < len_1; i++)
        {
            if (str2[0] == str1[i])
            {
                int pos = 0;
                for (int j = 0; j < len_2; j++)
                {
                    if (str1[i + j] == str2[j])
                    {
                        pos += 1;
                    }
                    else
                    {
                        pos += 0;
                    }
                }
                if (pos == len_2)
                {
                    return i + 1;
                }
                else
                {
                    return -1;
                }
            }
        }
    }

    return -1;
}

int main(void)
{
    char str1[100];
    char str2[100];

    fgets(str1, 100, stdin);
    fgets(str2, 100, stdin);

    printf("%d", getNum(str1, str2));
    return 0;
}