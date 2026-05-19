// problem link: https://www.hackerrank.com/challenges/playing-with-characters/problem?isFullScreen=true

#include <stdio.h>

int main()
{
    char ch;
    char s[100];
    char sen[1000];

    scanf("%c", &ch);
    scanf("%s\n", s);
    fgets(sen, 1000, stdin);

    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s", sen);

    return 0;
}
