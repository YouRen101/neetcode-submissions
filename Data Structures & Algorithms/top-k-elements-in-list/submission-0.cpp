class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i =0; i < nums.size(); ++i)
            mp[nums[i]]++;
        vector<pair<int,int>> arr;
        for(pair<int,int> m : mp)
            arr.push_back({m.first , m.second});
        sort(arr.begin() , arr.end() , [](pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;
        });
        vector<int> res;
        for(pair<int,int> x : arr){
            if(k > 0){
                res.push_back(x.first);
                k--;
            }
        }
        return res;
    }
};
