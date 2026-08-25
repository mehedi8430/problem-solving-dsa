// problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=binary-search

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[st] <= nums[mid])
            {
                // left side sorted, so apply bs here
                if (nums[st] <= target && target <= nums[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
            else
            {
                // right side sorted, so apply bs here
                if (nums[mid] <= target && target <= nums[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return -1;
    }
};