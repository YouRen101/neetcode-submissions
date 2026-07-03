class Solution {
public:
    int maxProfit(vector<int>& prices){
    int Max = 0, l =0 , r = 0;
    for(r =0 ; r < prices.size(); ++r){
        if(prices[r] < prices[l])
            l=r;
        Max = max(Max , prices[r]-prices[l]);
    }
    return Max;
}
};
