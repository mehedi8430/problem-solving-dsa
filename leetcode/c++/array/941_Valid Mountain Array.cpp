// problem link: https://leetcode.com/problems/valid-mountain-array/description/

#include <bits/stdc++.h>
using namespace std;

// approach 1
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();

        if (n < 3)
            return false;

        // calculate max value index in the array
        int mx = INT_MIN;
        int mx_idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mx)
            {
                mx = arr[i];
                mx_idx = i;
            }
        }

        // check if only increasing or decreasing
        if (mx_idx == 0 || mx_idx == n - 1)
            return false;

        // check increasing
        for (int i = 1; i <= mx_idx; i++)
        {
            if (arr[i] > arr[i - 1])
                continue;
            else
                return false;
        }

        // check decreasing
        for (int i = mx_idx; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                continue;
            else
                return false;
        }

        return true;
    }
};

// approach 2: two pointers
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();

        if (n < 3)
            return false;

        int left = 0;
        int right = n - 1;

        // Walk up from the left
        while (left + 1 < n && arr[left] < arr[left + 1])
        {
            left++;
        }

        // Walk down from the right
        while (right > 0 && arr[right - 1] > arr[right])
        {
            right--;
        }

        // Both sides must meet at the same peak,
        // and the peak cannot be at either end.
        if (left > 0 && left == right && right < n - 1)
            return true;
        else
            return false;
    }
};