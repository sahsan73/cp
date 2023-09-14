/*
Problem Statement: https://leetcode.com/problems/reverse-linked-list/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Iterative Implementation
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *r = 0, *q = 0, *p = head;
        while(p) {
            r = q, q = p, p = p->next;
            q->next = r;
        }
        return q;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Recursive Implementation
*/
class Solution {
private:
    ListNode *newHead;

    ListNode *dfs(ListNode *head) {
        if(head->next == nullptr) {
            newHead = head;
            return head;
        }

        ListNode *headNext = head->next;
        // we have to detach this link, otherwise there'll be a cycle in last
        // two nodes of the new reversed linked list.
        head->next = nullptr;
        dfs(headNext)->next = head;
        return head;
    }

public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;

        dfs(head);
        return newHead;
    }
};
