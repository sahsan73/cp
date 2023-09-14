/*
Problem Statement: https://leetcode.com/problems/linked-list-cycle-ii/description/
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return nullptr;

        // Step-I: check for cycle
        ListNode *slow = head, *fast = head;
        do {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        } while(fast && slow!=fast);
        if(fast == nullptr)
            return nullptr;

        // Step-II: find out position where cycle begins
        ListNode *pos = head;
        while(pos != slow) {
            pos = pos->next;
            slow = slow->next;
        }
        return pos;
    }
};
