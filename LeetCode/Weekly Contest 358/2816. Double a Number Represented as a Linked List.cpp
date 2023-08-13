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
class Solution {
private:
    ListNode *revLL(ListNode *head) {
        ListNode *p = head, *q = nullptr, *r = nullptr;
        while(p) {
            r = q;
            q = p;
            p = p->next;
            
            q->next = r;
        }
        return q;
    }
    
public:
    ListNode* doubleIt(ListNode* head) {
        head = revLL(head);
        int c = 0;
        ListNode *p = head, *q = nullptr;
        while(p) {
            int y = 2 * (p->val);
            p->val = (y + c)%10;
            c = (y)/10;
            
            q = p;
            p = p->next;
        }
        if(c)
            q->next = new ListNode(c);
        
        head = revLL(head);
        return head;
    }
};
