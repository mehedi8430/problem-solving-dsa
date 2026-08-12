// problem link: https://leetcode.com/problems/two-sum/description/

#include <bits/stdc++.h>
using namespace std;

// brute force way (O(n*n))
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
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

// using hash map(o(n) complexity)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];

            if (mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};