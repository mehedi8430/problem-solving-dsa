// problem link: https://www.hackerrank.com/challenges/printing-pattern-2/problem?isFullScreen=true

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int row = 2 * n - 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            int distance_from_top_or_bottom = i < (row - 1 - i) ? i : (row - 1 - i);
            int distance_from_left_or_right = j < (row - 1 - j) ? j : (row - 1 - j);

            int distance_from_nearest_edge = distance_from_top_or_bottom < distance_from_left_or_right ? distance_from_top_or_bottom : distance_from_left_or_right;

            printf("%d ", n - distance_from_nearest_edge);
        }

        printf("\n");
    }

    return 0;
}