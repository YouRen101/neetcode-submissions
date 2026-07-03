class Solution {
public:
    int maxArea(vector<int>& height){
    int maxf = -9999999;

    int l = 0, r = height.size()-1;
    while(l < r){
        if(height[l] <= height[r]){
            maxf = max(maxf , height[l]*(r-l));
            l++;
        }
        else{
            maxf = max(maxf , height[r]*(r-l));
            r--;
        }
    }

    return maxf;
}
};
