// problem link: https://leetcode.com/problems/sqrtx/description/?envType=problem-list-v2&envId=binary-search

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        if (x <= 3)
            return 1;

        int low = 1;
        int high = x;

        while (high >= low)
        {
            int mid = low + (high - low) / 2;
            long long square = (long long)mid * (long long)mid;

            if (square == x)
                return mid;
            else if (square > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return high;
    }
};