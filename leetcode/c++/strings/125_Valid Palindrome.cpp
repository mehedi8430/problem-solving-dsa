// problem link: https://leetcode.com/problems/valid-palindrome/description/?envType=problem-list-v2&envId=string

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAlphanumeric(char ch)
    {
        return ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'));
    }

    bool isPalindrome(string s)
    {
        int st = 0;
        int end = s.length() - 1;

        while (st < end)
        {
            if (!isAlphanumeric(s[st])) // // alphanumeric checking built-in function = isalnum(ch)
            {
                st++;
                continue;
            }

            if (!isAlphanumeric(s[end]))
            {
                end--;
                continue;
            }

            if (tolower(s[st]) != tolower(s[end]))
                return false;

            st++;
            end--;
        }

        return true;
    }
};