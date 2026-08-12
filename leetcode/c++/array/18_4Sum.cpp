// problem link: https://leetcode.com/problems/4sum/description/?envType=problem-list-v2&envId=array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n;)
            {
                int p = j + 1; // start/smallest pointer
                int q = n - 1; // end/largest pointer

                while (p < q)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                    if (sum < target)
                        p++;
                    else if (sum > target)
                        q--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        // Skip duplicate third elements
                        while (p < q && nums[p] == nums[p - 1])
                            p++;
                    }
                }

                j++;
                // Skip duplicate second elements
                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }
        }

        return ans;
    }
};