class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int pre = 1, post = 1;
        res.push_back(pre);
        for(int i = 0; i < n-1; ++i){
            pre *= nums[i];
            res.push_back(pre);
        }
        for(int i = n-2; i >= 0; --i){
            post *= nums[i+1];
            res[i] *= post;
        }
        return res;
    }
};
