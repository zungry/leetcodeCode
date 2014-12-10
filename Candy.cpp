class Solution {
public:
    int candy(vector<int> &ratings) {
        int len = ratings.size();
        if (len == 0 || len == 1) {
            return len;
        }
        
        int ret = 0;
        vector<int> candyNumber;
        int front = 1;
        candyNumber.push_back(1);

        
        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i-1]) {
                candyNumber.push_back(*(candyNumber.end()-1)+1);
            }
            else{
                candyNumber.push_back(1);
            }
        }
        
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyNumber[i] = max(candyNumber[i+1]+1,candyNumber[i]);
            }
        }
        
        for (int i = 0; i < len; i++) {
            ret +=candyNumber[i];
        }
        return ret;
    }
};