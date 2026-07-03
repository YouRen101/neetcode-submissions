class Solution {
public:
    string minWindow(string s, string t){
	if(t.empty()) return "";
	unordered_map<char, int> cnt_t , window;
	for(auto& c : t)
		cnt_t[c]++;
	int have = 0, need = cnt_t.size();
	int begin = -1;
	int resLen = INT_MAX;
	int l =0;

	for(int r = 0; r < s.size(); ++r){
		char c = s[r];
		window[c]++;

		if(cnt_t.count(c) && window[c] == cnt_t[c])
			have++;
		while(have == need){
			if(r-l+1 < resLen){
				resLen = r-l+1;
				begin = l;
			}

			window[s[l]]--;
			if(cnt_t.count(s[l]) && window[s[l]] < cnt_t[s[l]])
				have--;
			l++;
		}
	}
	return resLen == INT_MAX ? "" : s.substr(begin , resLen);
}
};