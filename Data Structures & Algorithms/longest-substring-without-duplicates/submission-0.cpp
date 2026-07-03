class Solution {
public:
    int lengthOfLongestSubstring(string s){
    unordered_set<char> st;
    int l = 0, r = 0,Max = 0;
    for(r = 0; r < s.size();++r){
        while(st.count(s[r])){
            Max = max(Max , int(st.size()));
            st.erase(s[l]);
            l++;
        }
        st.insert(s[r]);
    }
    Max = max(Max , int(st.size()));
    return Max;
}
};
