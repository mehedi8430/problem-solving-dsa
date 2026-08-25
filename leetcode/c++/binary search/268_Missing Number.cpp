// problem link: https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=binary-search

#include <bits/stdc++.h>
using namespace std;

// mathmatical approach -> O(n)
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = (n * (n + 1)) / 2;

        for (int i = 0; i < n; i++)
            sum -= nums[i];

        return sum;
    }
};

// XOR approach -> O(n)
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int result = n;

        for (int i = 0; i < n; i++)
        {
            result ^= i;
            result ^= nums[i];
        }

        return result;
    }
};

// binary search approach -> O(nlogn)
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int result = n;
        int l = 0, r = n - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] > mid)
            {
                result = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return result;
    }
};