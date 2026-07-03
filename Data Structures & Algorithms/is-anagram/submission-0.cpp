class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return 0;
        unordered_map<char , int> um1;
        for(int i =0 ;i < s.size(); ++i)
            um1[s[i]]++;
        unordered_map<char , int> um2 = um1;
        for(int i = 0; i < t.size(); ++i)
            um2[t[i]]++;
        for(int i = 0; i < s.size(); ++i){
            if((um2[s[i]]/um1[s[i]]) != 2)
                return 0;
        }
        return 1;
    }
};
