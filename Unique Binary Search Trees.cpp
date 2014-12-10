class Solution {
public:
    
    int bulidTree(int s,int e){
        if (e <= s) {
            return 1;
        }
        
        int nodes =  e - s + 1;
        
        if (dp[nodes]) {
            return dp[nodes];
        }
        
        int sum = 0;
        for (int i = s; i <= e; i++) {
            int ltdp = bulidTree(s, i-1);
            int rtdp = bulidTree(i+1, e);
            sum += ltdp * rtdp;
        }
        
        return dp[nodes] = sum ;
        
    }
    
    int numTrees(int n) {
        if (n <= 1) {
            return n;
        }
        
        memset(dp, 0, sizeof(dp));
        return  bulidTree(1, n);
    }
};
