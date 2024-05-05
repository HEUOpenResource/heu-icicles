#include <stdio.h>

char password(char alpha)
{
    return (alpha + 4 - 'a') % 26 + 'a';
    // if (alpha >= 'a' && alpha < 'w')
    // {
    //     return alpha + 4;
    // }
    // else if (alpha >= 'w' && alpha < 'z')
    // {
    //     return alpha + 4 - 26;
    // }
}

int main(void)
{
    char input[100];
    scanf("%s", input);
    for (int i = 0; i < 5; i++)
    {
        input[i] = password(input[i]);
    }
    printf("%s", input);
    return 0;
}
