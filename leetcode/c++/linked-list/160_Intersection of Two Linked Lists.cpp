// problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA != tempB) // time complexity: O(n+m)
        {
            if (tempA == NULL)
                tempA = headB;
            else
                tempA = tempA->next;

            if (tempB == NULL)
                tempB = headA;
            else
                tempB = tempB->next;
        }

        return tempA;
    }
};

// brute force -> time complexity: O(n*m)
// class Solution {
// public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//         for (ListNode* tempA = headA; tempA != NULL; tempA = tempA->next) {
//             for (ListNode* tempB = headB; tempB != NULL; tempB = tempB->next) {
//                 if (tempA == tempB)
//                     return tempA;
//             }
//         }
//         return NULL;
//     }
// };