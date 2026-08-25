// problem link: https://leetcode.com/problems/4sum-ii/description/?envType=problem-list-v2&envId=array

#include <bits/stdc++.h>
using namespace std;

// optimized: hashing approach (O(n*n))
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4)
    {
        int n = nums1.size();

        // Store the frequency of each pair sum from nums1 and nums2.
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = nums1[i] + nums2[j];
                mp[sum]++;
            }
        }

        int cnt = 0;

        // For each pair from nums3 and nums4, find its complementary sum
        // from nums1 and nums2 so that the total sum becomes zero.
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                int sum = nums3[k] + nums4[l];
                int needed = -sum;

                if (mp.find(needed) != mp.end())
                    cnt += mp[needed];
            }
        }

        return cnt;
    }
};

// brute force (O(n*n*n*n))
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int n = nums1.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        int sum = nums1[i] + nums2[j] + nums3[k] + nums4[l];
                        if (sum == 0)
                            cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};