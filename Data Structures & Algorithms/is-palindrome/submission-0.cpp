class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> ani;
        for(int i =0 ;i < s.size(); ++i){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                ani.push_back(s[i]);
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                int macos = 'a'-'A';
                ani.push_back(s[i]+macos);
            }
        }
        for(int i = 0; i < ani.size(); ++i){
            if(ani[i] != ani[ani.size()-1-i]){
                return 0;
            }
        }
        return 1;
    }
};