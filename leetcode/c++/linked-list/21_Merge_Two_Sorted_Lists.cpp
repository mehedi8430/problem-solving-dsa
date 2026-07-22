// problem link: https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=problem-list-v2&envId=linked-list

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // If one list is empty, return the other
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *head;
        ListNode *tmp1 = list1;
        ListNode *tmp2 = list2;

        // Choose the first node of the merged list
        if (tmp1->val < tmp2->val)
        {
            head = tmp1;
            tmp1 = tmp1->next;
        }
        else
        {
            head = tmp2;
            tmp2 = tmp2->next;
        }

        ListNode *curr = head;

        // Merge while both lists have nodes
        while (tmp1 != NULL && tmp2 != NULL)
        {
            if (tmp1->val < tmp2->val)
            {
                curr->next = tmp1;
                tmp1 = tmp1->next;
            }
            else
            {
                curr->next = tmp2;
                tmp2 = tmp2->next;
            }
            curr = curr->next;
        }

        // Attach the remaining nodes
        if (tmp1 != NULL)
            curr->next = tmp1;
        if (tmp2 != NULL)
            curr->next = tmp2;

        return head;
    }
};