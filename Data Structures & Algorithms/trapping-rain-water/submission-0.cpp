class Solution {
public:
    int trap(vector<int>& height){
        int res = 0;
        int l = 0, r = height.size()-1;
        int maxL = height[l] , maxR = height[r];
        while(l < r){
            if(height[l] <= height[r]){
                l++;
                maxL = max(maxL , height[l]);
                int minux = maxL-height[l];
                res += minux;
            }
            else{
                r--;
                maxR = max(maxR , height[r]);
                int minux = maxR-height[r];
                res += minux;
            }
        }
        return res;
    }
};
