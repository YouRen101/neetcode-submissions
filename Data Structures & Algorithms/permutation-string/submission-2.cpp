class Solution {
public:
    bool checkInclusion(string s1, string s2){
	if(s1.size() > s2.size()) return 0;

	vector<int> cnt_s1(26,0);
	vector<int> cnt_s2(26,0);
	int matches = 0;

	for(int i =0; i < s1.size(); ++i)
		cnt_s1[s1[i]-'a']++ , cnt_s2[s2[i] - 'a']++;
	for(int i =0 ;i < 26;++i)
		if(cnt_s1[i] == cnt_s2[i])
			matches++;

	int l =0;
	for(int r = s1.size(); r < s2.size(); ++r){
		if(matches == 26) return 1;

		int idx = s2[r]-'a';
		cnt_s2[idx]++;
		if(cnt_s1[idx] == cnt_s2[idx]) matches++;
		else if(cnt_s1[idx]+1 == cnt_s2[idx]) matches--;

		idx = s2[l]-'a';
		cnt_s2[idx]--;
		if(cnt_s1[idx] == cnt_s2[idx]) matches++;
		else if(cnt_s1[idx]-1 == cnt_s2[idx]) matches--;
		l++;
	}
	return matches == 26;
}
};
