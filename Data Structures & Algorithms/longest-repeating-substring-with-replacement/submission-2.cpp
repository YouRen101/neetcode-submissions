class Solution {
public:
    int characterReplacement(string s, int k){
	unordered_map<char,int> mp;
	int l = 0;
	int Max = 0, res =0;
	for(int r = 0; r < s.size(); ++r){
		mp[s[r]]++;
		Max = max(mp[s[r]] , Max);
		while((r-l+1)-Max > k){
			mp[s[l]]--;
			l++;
		}
		res = max(res , r-l+1);
	}
	return res;
}
};
