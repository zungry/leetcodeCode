class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        int i = 0;
        int len = prices.size();
        if(len<2)
            return 0;
        for(i=1;i<len;++i)
        {
            if(prices[i]>prices[i-1])
            {
                result += prices[i]-prices[i-1];
            }
        }
        return result;

    }
};

