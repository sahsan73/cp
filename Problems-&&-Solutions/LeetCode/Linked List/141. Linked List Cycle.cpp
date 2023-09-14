/*
Problem Statement: https://leetcode.com/problems/linked-list-cycle/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: FLOYD'S ALGORIGHTM OR HARE-TORTOISE ALGORITHM

COMPLEXITY:
    TC = O(n)
    SC = O(1)
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return 0;

        ListNode *slow = head, *fast = head;
        do {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        } while(fast && slow!=fast);

        return fast != nullptr;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: HASHMAP

COMPLEXITY:
    TC = O(n)
    SC = O(n)
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode *> st;
        while(head) {
            if(st.count(head))
                return 1;
            st.insert(head);
            head = head->next;
        }
        return 0;
    }
};
