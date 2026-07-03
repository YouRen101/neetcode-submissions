class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for(char& c : s){
            if(sk.empty())
                sk.push(c);
            else{
                if(sk.top() == '(' && c == ')'
                    || (sk.top() == '[' && c == ']')
                    || (sk.top() == '{' && c == '}'))
                    sk.pop();
                else sk.push(c);
            }
        }
        if(sk.empty()) return 1;
        return 0;
    }
};