class Solution {
public:
    string minWindow(string s, string t){
    if(t.empty()) return "";

    unordered_map<char , int> window , cnt_t; 
    for(auto& x : t) cnt_t[x]++;
    
    int l =0 , r,need = cnt_t.size(), have = 0;
    int resLen = INT_MAX , start = l;

    for(r = 0; r < s.size(); ++r){
        char c = s[r];
        window[c]++;

        if(cnt_t.count(c) && window[c] == cnt_t[c])  have++;

        while(have == need){
            if(r-l+1 < resLen){
                resLen= r-l+1;
                start= l;
            }

            window[s[l]]--;
            if(cnt_t.count(s[l]) && cnt_t[s[l]] > window[s[l]]) have--;
            l++;
        }
    }

    return resLen == INT_MAX ? "" : s.substr(start , resLen);
}

};
