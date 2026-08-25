// problem link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=problem-list-v2&envId=string

#include <bits/stdc++.h>
using namespace std;

// O(n*n*m)
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        while (s.length() > 0 && s.find(part) < s.length())
            s.erase(s.find(part), part.length());

        return s;
    }
};

// O(n*m)
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string st = ""; // Acting as a stack
        int n = part.length();

        for (char c : s)
        {
            st.push_back(c);

            // If the current stack size is at least the length of 'part'
            // and the suffix matches 'part', remove it.
            if (st.size() >= n && st.substr(st.size() - n) == part)
                st.erase(st.size() - n);
        }

        return st;
    }
};