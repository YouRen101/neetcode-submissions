class Solution {
public:
    int trap(vector<int>& height){
	int l =0, r = height.size()-1;
	int maxL = height[l], maxR = height[r], res =0;
	while(l < r){
		if(height[l] <= height[r]){
			l++;
			maxL = max(maxL , height[l]);
			res += (maxL-height[l]);
		}
		else{
			r--;
			maxR = max(maxR , height[r]);
			res += (maxR-height[r]);
		}
	}
	return res;
}
};
