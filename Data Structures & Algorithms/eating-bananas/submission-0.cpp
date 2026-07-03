class Solution {
public:
    bool isOK(int& m, vector<int>& piles, int& h){
    int time = 0;
    for(auto& x : piles)
        time += ceil(1.00*x/m);
    if(time <= h)
        return 1;
    return 0;
}

int minEatingSpeed(vector<int>& piles, int h){
    int l  = 1;int r = 0;
    int res = 0;
    for(int i = 0; i < piles.size();++i)
        r = max(r , piles[i]);
    while(l <= r){
        int m = (l+r)/2;
        if(isOK(m, piles, h)){
            res = m;
            r = m-1;
        }
        else
            l = m+1;
    }
    return res;
}
};
