class Solution {
public:
    int longestConsecutive(vector<int>& nums){
	int res =0 , l;
	unordered_set<int> st;
	for(auto& x: nums) st.insert(x);
	for(auto& x : nums){
		if(st.count(x-1)) continue;
  		l = 0;
  		while(st.count(x)){
  			l++;
            x++;
        }
  		res = max(res , l);
	}
	return res;
}
};
