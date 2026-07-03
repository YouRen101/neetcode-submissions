class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mp;
        for(auto& str : strs){
            vector<int> cnt(26 , 0);
            for(auto& c : str)
                cnt[c - 'a']++;
            string key = to_string(cnt[0]);
            for(int i = 1; i < 26; ++i)
                key += "," + to_string(cnt[i]);
            mp[key].push_back(str);
        }
        vector<vector<string>> res;
        for(pair<string , vector<string>> arr : mp)
            res.push_back(arr.second);
        return res;
    }
};
