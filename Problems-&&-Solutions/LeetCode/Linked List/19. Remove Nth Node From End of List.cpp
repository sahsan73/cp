/*
Problem Statement: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p2 = head, *p1 = head;
        for(int i=0; i<n; ++i)
            p2 = p2->next;
        if(p2 == nullptr)
            return head->next;

        while(p2->next) {
            p2 = p2->next;
            p1 = p1->next;
        }
        p1->next = p1->next->next;
        return head;
    }
};
