class Solution {
private:
    unordered_map<Node* , Node*> mp;
public:
    Node* rec(Node* cur){
        if(!cur) return nullptr;
        mp[cur] = new Node(cur->val);
        mp[cur]->next = rec(cur->next);
        mp[cur]->random = mp[cur->random];
        return mp[cur];
    }   

    Node* copyRandomList(Node* head) {
        mp[nullptr] = nullptr;
        return rec(head);
    }
};