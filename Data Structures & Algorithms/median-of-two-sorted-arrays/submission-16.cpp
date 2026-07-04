class Solution {
public:
    int getkth(vector<int>& a,int m , vector<int>& b, int n ,int k , int astart , int bstart){
        if(m > n){
            return getkth(b , n,a , m , k , bstart , astart);
        }

        if(m == 0) return b[bstart+k-1];
        if(k == 1)
            return min(a[astart] , b[bstart]);
        int i = min(m , k/2);
        int j = min(n , k/2);
        
        if(a[astart+i-1] < b[bstart+j-1])
            return getkth(a , m-i , b , n ,k-i, astart+i , bstart);
        else return getkth(a , m , b , n-j ,k-j, astart , bstart+j);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = nums1;                 
        vector<int>& b = nums2;
        int m = a.size();
        int n = b.size();

        int l = (n+m+1)/2;
        int r = (n+m+2)/2;
        return (getkth(a, m , b ,n , l , 0 , 0) + 
            getkth(a,m,b,n,r,0,0))/2.0;
    }
};