class Solution {
public:
    int maxArea(vector<int>& height){
        int maxArea = -1e9,curArea;
        int l = 0, r = height.size()-1;
        while(l < r){
            curArea = min(height[l] , height[r])*(r-l);
            maxArea = max(maxArea , curArea);
            if(height[l] < height[r])
                l++;
            else r--;
        }
        return maxArea;
    }
};