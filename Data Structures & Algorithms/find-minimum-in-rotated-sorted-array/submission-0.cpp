class Solution {
public:
    int findMin(vector<int>& nums){
    if(nums[0] <= nums.back()) return nums[0];
    int l = 0,  r = nums.size()-1;
    int res = 0;
    while(l <= r){
        int m = (l+r)/2;
        if(nums[m] <= nums.back()){
            r = m-1;
            res = nums[m];
        }
        else l= m+1;
    }
    return res;
}
};
