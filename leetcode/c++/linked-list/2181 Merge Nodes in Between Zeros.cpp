// problem link: https://leetcode.com/problems/merge-nodes-in-between-zeros/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        head = head->next;
        ListNode *tmp1 = head;
        ListNode *tmp2 = head;
        int sum = 0;

        while (1)
        {
            if (tmp2->val == 0)
            {
                tmp1->val = sum;
                sum = 0;
                if (tmp2->next == NULL)
                {
                    tmp1->next = NULL;
                    break;
                }
                tmp1 = tmp1->next;
            }
            else
            {
                sum += tmp2->val;
            }
            tmp2 = tmp2->next;
        }
        return head;
    }
};