class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i) {
            um[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (um[nums[i]] > 1)
                return true;
        }
        return false;
    }
};