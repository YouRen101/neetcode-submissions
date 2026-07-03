class Solution {
public:
    bool hi(char x , char y){
        return ((x == '(' && y == ')')
        || (x == '[' && y == ']')
        || (x == '{' && y == '}'));
    }

    bool isValid(string s) {
        stack<int> q;
        for(int i = 0; i < s.size(); ++i){
            if(!q.empty() && hi(q.top() , s[i]))
                q.pop();
            else q.push(s[i]);
        }      
        return q.empty();
    }
};