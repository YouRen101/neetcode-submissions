
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l <= r){
            if((s[l] < 'a' || s[l] > 'z') && (s[l] < 'A' || s[l] > 'Z') 
                && (s[l] < '0' || s[l] > '9')){
                l++; continue;
            }
            if((s[r] < 'a' || s[r] > 'z') && (s[r] < 'A' || s[r] > 'Z') 
                    && (s[r] < '0' || s[r] > '9')){
                r--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r]))
                return 0;
            l++;r--;
        }
        return 1;
    }
};