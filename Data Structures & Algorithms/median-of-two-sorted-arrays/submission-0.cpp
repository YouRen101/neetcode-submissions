class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    vector<int>& a = nums1;
    vector<int>& b = nums2;

    int tt = a.size()+b.size();
    if(a.size() > b.size())
        swap(a,b);
    int half = (tt+1)/2;

    int l = 0, r = a.size();
    while(l <= r){
        int i = (l+r)/2;
        int j = half-i;

        int Aleft = i > 0 ? a[i-1] : INT_MIN;
        int Aright = i < a.size() ? a[i] : INT_MAX;
        int Bleft = j > 0 ? b[j-1] : INT_MIN;
        int Bright =j < b.size() ? b[j] : INT_MAX;

        if(Aleft <= Bright && Bleft <= Aright){
            if(tt%2 != 0)
                return max(Aleft , Bleft);
            return (max(Aleft , Bleft) + min(Aright , Bright))/2.0;
        }
        else if(Aleft > Bright)
            r = i-1;
        else l = i+1;
    }
    return -1;
}
};
