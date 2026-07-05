// problem link: https://www.hackerrank.com/challenges/frequency-of-digits-1/problem?isFullScreen=true

#include<stdio.h>
#include<string.h>

int main()
{
    char num[1005];
    scanf("%s", num);

    int freq[10]={0};
    int len = strlen(num);

    for (int i = 0; i < len; i++)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            // Convert char digit to integer index by subtracting '0'
            int digit = num[i] - '0';
            freq[digit]++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d", freq[i]);
        if (i < 9) {
            printf(" "); 
        }
    }
    printf("\n");

    return 0;
}