class Solution {
public:
    int findMin(vector<int> &nums){
	int l = 0, r = nums.size()-1;
	int res = 0;
	while(l <= r){
		int m = (l+r)/2;
		if(nums[m] <= nums.back()){
			res = nums[m];
			r = m-1;
		}
		else l = m+1;
	}
	return res;
}
};
