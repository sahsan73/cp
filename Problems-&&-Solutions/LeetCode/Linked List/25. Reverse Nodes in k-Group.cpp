/*
Problem Statement: https://leetcode.com/problems/reverse-nodes-in-k-group/description/
*/

class Solution {
private:
    void revLL(ListNode *p) {
        ListNode *q = nullptr, *r = q;
        while(p) {
            r = q, q = p, p = p->next;
            q->next = r;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode(0), *newTail = newHead;

        while(head) {
            ListNode *a = head, *b = nullptr;
            int cnt = 0;
            for(int i=0; i<k&&head; ++i) {
                b = head;
                head = head->next;
                ++cnt;
            }
            b->next = nullptr;

            if(cnt == k) {
                revLL(a);
                newTail->next = b;
                newTail = a;
            } else {
                newTail->next = a;
                newTail = b;
            }
        }

        return newHead->next;
    }
};
