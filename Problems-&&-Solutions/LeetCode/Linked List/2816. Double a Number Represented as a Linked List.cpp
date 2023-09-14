/*
Problem Statement: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (head->val > 4)
            head = new ListNode(0, head);
        for(ListNode* curr = head; curr; curr = curr->next) {
            curr->val = (curr->val * 2) % 10;
            if (curr->next && curr->next->val > 4)
                curr->val++;
        }
        return head;
    }
 };

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: RECURSION
*/
class Solution {
private:
    int carry = 0;

    void dfs(ListNode *head) {
        if(head == nullptr) return;
        dfs(head->next);

        int r = 2 * (head->val) + carry;
        head->val = r%10;
        carry = r/10;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        carry = 0;
        dfs(head);
        if(carry)
            head = new ListNode(carry, head);
        return head;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
private:
    ListNode *revLL(ListNode *p) {
        ListNode *q = 0, *r = 0;
        while(p) {
            r = q, q = p, p = p->next;
            q->next = r;
        }
        return q;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        head = revLL(head);
        int carry = 0;
        for(ListNode *curr=head; curr; curr=curr->next) {
            int r = 2 * (curr->val) + carry;
            curr->val = r % 10;
            carry = r / 10;
        }
        head = revLL(head);
        if(carry)
            head = new ListNode(carry, head);
        return head;
    }
};
