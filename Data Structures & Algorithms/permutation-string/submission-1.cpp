class Solution {
public:
    bool checkInclusion(string s1, string s2){
	if(s1.size() > s2.size())
		return 0;

	vector<int> s1_cnt(26 , 0);
	vector<int> s2_cnt(26 , 0);
	for(int i =0 ;i < s1.size(); ++i){
		s1_cnt[s1[i]-'a']++;
		s2_cnt[s2[i]-'a']++;
	}

	int matches = 0;

	for(int i = 0; i < 26;++i)
		if(s1_cnt[i] == s2_cnt[i]) matches++;

	int l =0 ;
	for(int r = s1.size(); r < s2.size(); ++r){
		if(matches == 26) return 1;

		//chỉ mục của phần tử cuối đoạn con s2
		int index = s2[r]-'a';
		s2_cnt[index]++;
		if(s1_cnt[index] == s2_cnt[index]) matches++;
		else if(s1_cnt[index]+1 == s2_cnt[index]) matches--;

		index = s2[l] - 'a';
		s2_cnt[index]--;
		if(s1_cnt[index] == s2_cnt[index]) matches++;
		else if(s1_cnt[index]-1 == s2_cnt[index]) matches--;
		l++;

	}
	return matches == 26;
}
};
