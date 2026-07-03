class Solution {
public:
    int lengthOfLongestSubstring(string s){
	unordered_set<char> cnt;
	int maxf = 0;

	int l = 0;
	
	for(int r = 0; r < s.size(); ++r){
		while(cnt.count(s[r])){
			cnt.erase(s[l]);
			l++;
		}
		cnt.insert(s[r]);
		maxf = max(maxf , r-l+1);
	}
	return maxf;
}

};
