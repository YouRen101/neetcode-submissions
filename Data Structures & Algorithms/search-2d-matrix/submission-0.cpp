class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
    for(auto& a : matrix){
        if(a.back() < target) continue;
        int l = 0, r = a.size()-1;
        while(l <= r){
            int m = (l+r)/2;
            if(a[m] == target)
                return 1;
            else if(a[m] < target)
                l = m+1;
            else r = m-1;
        }
    }
    return 0;
}
};
