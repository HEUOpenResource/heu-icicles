#include <stdio.h>
#include <string.h>

// 返回回文子串的长度
int longestSymmetricSubstring(char *s)
{
    int len = strlen(s);
    int maxLength = 0;

    // 遍历字符串
    for (int center = 0; center < 2 * len - 1; center++)
    {
        int left = center / 2;
        int right = left + center % 2;

        // 找到中心并向两侧扩展
        while (left >= 0 && right < len && s[left] == s[right])
        {
            maxLength = (right - left + 1) > maxLength ? (right - left + 1) : maxLength;
            left--;
            right++;
        }
    }

    return maxLength;
}

int main()
{
    char str[1001]; // 为了容纳1000个字符及结束符'\0'

    // 读取输入字符串
    fgets(str, 1001, stdin);
    str[strcspn(str, "\n")] = '\0'; // 去除换行符

    // 计算最长对称子串的长度并输出
    int result = longestSymmetricSubstring(str);
    printf("%d\n", result);

    return 0;
}