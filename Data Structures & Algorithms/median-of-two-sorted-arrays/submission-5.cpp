#define INF 1e9

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = nums1;
        vector<int>& b = nums2;

        if(a.size() > b.size())
            swap(a,b);

        int s = a.size()+b.size();
        int half = (s+1)/2;

        int l = 0, r = a.size();
        while(l <= r){
            int m = (l+r)/2;
            int n = half-m;

            int la = m > 0 ? a[m-1] : -INF;
            int ra = m != a.size() ? a[m] : INF;
            int lb = n > 0 ? b[n-1] : -INF;
            int rb = n != b.size() ? b[n] : INF;

            if(la <= rb && lb <= ra){
                if(s%2 != 0)
                    return max(la , lb);
                else return (max(la,lb) + min(ra , rb))*1.00/2;
            }
            else if(lb > ra)
                l = m+1;
            else r = m-1;
        }
    }
};