// problem link: https://www.hackerrank.com/challenges/hello-world-c/problem?isFullScreen=true

#include <stdio.h>

int main() 
{
	
    char s[100];
    fgets(s, 100, stdin);
    
    printf("Hello, World!\n%s", s);
  	
    return 0;
}
