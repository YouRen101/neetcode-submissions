class Solution {
public:
    int trap(vector<int>& height) {
        int cnt = 0, max_l = 0, max_r = 0;
        int l = 0, r = height.size()-1;
        while(l <= r){
            max_l = max(max_l , height[l]);
            max_r = max(max_r , height[r]);

            if(height[l] < height[r]){
                cnt += max_l-height[l];
                l++;
            }
            else{
                cnt += max_r-height[r];
                r--;
            }
        }

        return cnt;        
    }
};