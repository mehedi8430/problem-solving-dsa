// problem link: https://www.hackerrank.com/challenges/sum-of-digits-of-a-five-digit-number/problem?isFullScreen=true

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;

    while (n != 0)
    {
        int last_digit = n % 10;
        sum += last_digit;
        n /= 10;
    }

    printf("%d", sum);

    return 0;
}