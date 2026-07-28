// problem link: https://leetcode.com/problems/swap-nodes-in-pairs/description/

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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *previous = NULL;
        head = head->next;

        while (true)
        {
            first->next = second->next;
            second->next = first;
            if (previous != NULL)
                previous->next = second;

            previous = first;
            first = first->next;
            if (first == NULL)
                break;
            second = first->next;
            if (second == NULL)
                break;
        }

        return head;
    }
};

// solved using recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* first = head;
        ListNode* second = head->next;

        // Swap the remaining list
        first->next = swapPairs(second->next);

        // Complete the swap
        second->next = first;

        return second;
    }
};