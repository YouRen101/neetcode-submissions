class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
    deque<int> q;
    vector<int> res;

    int l = 0, r;

    for(r = 0; r < nums.size();++r){
        while(!q.empty() && nums[r] > nums[q.back()]) q.pop_back();
        q.push_back(r);

        if(r+1 >= k){
            res.push_back(nums[q.front()]);
            l++;
        }

        if(!q.empty() && l > q.front()) q.pop_front();
    }

    return res;
}

};
