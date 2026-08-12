// problem link: https://leetcode.com/problems/two-sum/description/

#include <bits/stdc++.h>
using namespace std;

// 1. brute force way (O(n*n))
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    nums.clear();
                    nums.push_back(i);
                    nums.push_back(j);
                    return nums;
                }
            }
        }

        return {};
    }
};

// 2. better approach: sorting + two pointers (O(nlogn))
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> arr;

        // Store {value, original_index}
        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        while (left < right)
        {
            int sum = arr[left].first + arr[right].first;

            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
                return {arr[left].second, arr[right].second};
        }

        return {};
    }
};

// 3. optimized: using hashing (o(n))
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int first = nums[i];
            int second = target - first;

            if (mp.find(second) != mp.end()) // in unordered map find method complexity is O(1)
            {
                return {mp[second], i};
            }

            mp[first] = i;
        }

        return {};
    }
};