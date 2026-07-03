class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> m;
        for(int i = 0; i < nums.size(); ++i){
            int yeah = target-nums[i];
            if(m.find(yeah) != m.end())
                return {m[yeah] , i};
            m[nums[i]] = i;
        }
        return {};
    }
};
