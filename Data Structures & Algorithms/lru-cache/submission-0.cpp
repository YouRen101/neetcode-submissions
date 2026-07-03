class Node{
public:
    int key;
    int val;

    Node* next;
    Node* prev;
    
    Node(int k , int v) : key(k) , val(v) , next(nullptr) , prev(nullptr) {};
};


class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:
    LRUCache(int capacity){
        cap = capacity;
        cache.clear();
        right = new Node(0 , 0);
        left = new Node(0 , 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key){
        if(cache.count(key)){
            Node* temp = cache[key];
            remove(temp);
            insert(temp);
            return temp->val;
        }
        return -1;
    }

    void put(int key , int value){
        if(cache.count(key)){
            remove(cache[key]);
        }
        
        Node* nd = new Node(key , value);
        cache[key] = nd;
        insert(nd);
        if(cache.size() > cap){
            Node* temp = left->next;
            remove(temp);
            cache.erase(temp->key);
            delete temp;
        }
    }
};

