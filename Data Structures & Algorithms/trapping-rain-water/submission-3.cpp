class Solution {
public:
    int trap(vector<int>& height){
    int trap = 0;
    int l = 0, r = height.size()-1;
    int maxL = height[l],maxR = height[r];

    while(l < r){
        if(height[l] < height[r]){
            maxL = max(maxL , height[l]);
            trap += maxL - height[l];
            l++;
        }
        else{
            maxR = max(maxR , height[r]);
            trap += maxR - height[r];
            r--;
        }
    }

    return trap;
}

};
