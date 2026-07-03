class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
        unordered_map<int,int> cnt;
        
        for(int i = 0 ;i < nums.size(); ++i){
            cnt[nums[i]]++;
        }

        for(auto& x : cnt){
            q.push({x.second , x.first});
            if(q.size() > k)
                q.pop();
        }

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }

        return res;
    }       
};
