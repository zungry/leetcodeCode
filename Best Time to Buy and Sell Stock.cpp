class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1)
            return 0;
            
        int ret = 0;
        int maxSale = prices[prices.size()-1];
        
        
        for(int i = prices.size()-2;i >=0;--i){
            maxSale = max(prices[i],maxSale);
            ret = max(maxSale-prices[i],ret);
        }
        return ret;
    }
};