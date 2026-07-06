class Solution {
public:
    ListNode* con( vector<ListNode*> lists , ListNode* left , ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while(left && right){
            if(left->val < right->val){
                cur->next = left;
                left = left->next;
            }
            else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }

        while(left){
            cur->next = left;
            left = left->next;
            cur = cur->next;
        }

        while(right){
            cur->next = right;
            right = right->next;
            cur = cur->next;
        }

        cur = dummy->next;
        delete(dummy);
        return cur;
    }

    ListNode* divide(vector<ListNode*>& lists , int l , int r){
        if(l > r) return nullptr;
        if(l == r) return lists[l];

        int m = (l+r)/2;
        ListNode* left = divide(lists , l , m);
        ListNode* right = divide(lists , m+1, r);

        return con(lists , left , right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return divide(lists , 0 , lists.size()-1);
    }
};
