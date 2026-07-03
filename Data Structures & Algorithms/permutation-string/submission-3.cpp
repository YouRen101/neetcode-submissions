class Solution {
public:
    bool checkInclusion(string s1, string s2 ){
    vector<int> s1_cnt(26,0);
    vector<int> s2_cnt(26,0);

    int matches = 0;

    for(int i =0 ; i < s1.size(); ++i)
        s1_cnt[s1[i]-'a']++, s2_cnt[s2[i]-'a']++;

    for(int i =0 ; i < 26; ++i)
        if(s1_cnt[i] == s2_cnt[i]) matches++;

    int l = 0,r, idx;

    for(r = s1.size(); r < s2.size(); ++r){
        if(matches == 26) return 1;

        idx = s2[r]-'a';
        s2_cnt[idx]++;
        if(s2_cnt[idx] == s1_cnt[idx]) matches++;
        else if(s2_cnt[idx] == s1_cnt[idx]+1) matches--;

        idx = s2[l]-'a';
        s2_cnt[idx]--;
        if(s2_cnt[idx] == s1_cnt[idx]) matches++;
        else if(s2_cnt[idx] == s1_cnt[idx]-1) matches--;
        l++;
    }

    return matches == 26;
}

};
