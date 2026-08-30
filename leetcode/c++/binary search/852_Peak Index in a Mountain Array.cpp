// problem link: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/?envType=problem-list-v2&envId=binary-search

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int st = 1;
        int end = arr.size() - 2;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] > arr[mid - 1]) // right(increasing slope)
                st = mid + 1;
            else // left(decreasing slope)
                end = mid - 1;
        }

        return -1;
    }
};