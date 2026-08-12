// problem link: https://leetcode.com/problems/3sum/description/?envType=problem-list-v2&envId=array

#include <bits/stdc++.h>
using namespace std;

// sorting + two pointers = O(n²)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++)
        {
            // No possible triplet if first number is positive
            if (nums[i] > 0)
                break;

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate second elements
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                }
            }
        }

        return ans;
    }
};