class Solution {
public:
    string minWindow(string s, string t){
	if(t.empty()) return 0;
	unordered_map<char,int> cnt_t , window;
	for(auto& c : t) cnt_t[c]++;

	int begin = -1, resLen = INT_MAX;
	int have = 0, need = cnt_t.size();

	int l = 0;
	for(int r = 0 ; r < s.size(); ++r){
		char c = s[r];
		window[c]++;

		if(cnt_t.count(c) && window[c] == cnt_t[c])
			have++;
		while(have == need){
			if(r-l+1 < resLen){
				resLen = r-l+1;
				begin = l;
			}
			c = s[l];
			window[c]--;
			if(window[c] < cnt_t[c])
				have--;
			l++;
		}
	}
	return resLen == INT_MAX ? "" : s.substr(begin , resLen);
}
};