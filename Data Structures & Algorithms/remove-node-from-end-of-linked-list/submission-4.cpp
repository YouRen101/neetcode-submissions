class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0 , head);
        ListNode* l = dummy;
        ListNode* r = head;

        while(n > 0){
            r = r->next;
            n--;
        }
        while(r){
            l = l->next;
            r = r->next;
        } 

        l->next = l->next->next;
        return dummy->next; //head có thể là node bị xóa
    }
};