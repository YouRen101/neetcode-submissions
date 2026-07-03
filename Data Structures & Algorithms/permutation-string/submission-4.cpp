class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    vector<int> s1_cnt(26,0);
    vector<int> s2_cnt(26,0);

    int matches = 0;

    for(int i = 0; i < s1.size(); ++i){
        s1_cnt[s1[i]-'a']++;
        s2_cnt[s2[i]-'a']++;
    }

    int l = 0;

    for(int i = 0; i < 26; ++i)
        if(s1_cnt[i] == s2_cnt[i]) matches++;

    for(int r = s1.size(); r < s2.size(); ++r){
        if(matches == 26) return 1;

        int idx = s2[r] -'a';
        s2_cnt[idx]++;
        if(s1_cnt[idx] == s2_cnt[idx]) matches++;
        else if(s1_cnt[idx]+1 == s2_cnt[idx]) matches--;

        idx = s2[l] - 'a';
        s2_cnt[idx]--;
        if(s1_cnt[idx] == s2_cnt[idx]) matches++;
        else if(s1_cnt[idx]-1 == s2_cnt[idx]) matches--;
        l++;
    }
    return matches == 26;
}

};
