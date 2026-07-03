vector<string> phone = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "qprs", "tuv", "wxyz"
        };

class Solution {
private:
    vector<string> res;
public:
    void backtrack(string& sub , string& digits, int idx){
        if(idx >= digits.size()){
            res.push_back(sub);
            return;
        }


        for(auto& c : phone[digits[idx]-'0' ]){
            sub += c;
            
            backtrack(sub , digits , idx+1);
            sub.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {  
        if(digits.empty()) return res;

        string sub = "";

        backtrack(sub, digits , 0);

        return res;
    }
};
