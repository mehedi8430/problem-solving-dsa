// problem link: https://www.hackerrank.com/challenges/printing-tokens-/problem?isFullScreen=true

#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1005];
    fgets(sentence, sizeof(sentence), stdin);
    int len = strlen(sentence);

    for (int i = 0; i < len; i++)
    {
        if (sentence[i] == ' ')
            printf("\n");
        else if (sentence[i] != '\n')
            printf("%c", sentence[i]);
    }

    return 0;
}