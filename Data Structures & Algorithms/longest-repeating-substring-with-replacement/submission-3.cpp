class Solution {
public:
    int characterReplacement(string s, int k){
    unordered_map<int,int> cnt;

    int l = 0, r, maxf = INT_MIN, res = 0;

    for(r = 0; r < s.size(); ++r){
        cnt[s[r]]++;
        maxf = max(maxf , cnt[s[r]]);

        if((r-l+1)-maxf > k){
            cnt[s[l]]--;
            l++;
        }
    
        res = max(res , r-l+1);    
    }

    return res;
}
};
