class Solution {
public:
    ListNode* rec(ListNode* cur , int& n){
        if(!cur) return nullptr;
        cur->next = rec(cur->next , n);
        n--;
        if(!n)
            return cur->next;
        return cur;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //ListNode* dummy = new ListNode*(0,head);
        return rec(head , n);
    }
};