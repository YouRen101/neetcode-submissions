class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size()-1;
        int maxl = height[l] , maxr = height[r];

        while(l <= r){
            if(height[l] < height[r]){
                maxl = max(maxl , height[l]);
                res += maxl-height[l];
                l++;
            }
            else{
                maxr = max(maxr , height[r]);
                res += maxr - height[r];
                r--;
            }
        }

        return res;
    }
};
