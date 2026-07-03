class Solution {
public:
    string encode(vector<string>& strs){
        string str = "";
        for(auto& s : strs)
            str += s + "|";
        return str;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string str = "";
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '|'){
                res.push_back(str);
                str = "";
            }
            else
                str += s[i];
        }
        return res;
    }
};
