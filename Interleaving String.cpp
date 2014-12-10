class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s1.size() == 0 && s2.size() == 0 && s3.size()==0) {
            return true;
        }
        
        if (s1.size() == 0) {
            if (s2.size() != s3.size()) {
                return false;
            }
            for (int i = 0 ; i < s2.size(); i++) {
                if (s2[i] != s3[i]) {
                    return false;
                }
            }
            return true;
        }
        
        
        if (s2.size() == 0) {
            if (s1.size() != s3.size()) {
                return false;
            }
            for (int i = 0 ; i < s1.size(); i++) {
                if (s1[i] != s3[i]) {
                    return false;
                }
            }
            return true;
        }
        
        
        if(s1.size()+s2.size() != s3.size()){
            return false;
        }
        
        bool **dp = new bool *[s1.size()+1];
        for (int i = 0; i < s1.size()+1; i++) {
            dp[i] = new bool[s2.size()+1];
        }
        
        dp[0][0] = true;
        
        for (int i = 1; i < s1.size()+1; i++) {
            dp[i - 1][0] && s1[i - 1] == s3[i - 1] ? dp[i][0] = true : dp[i][0] = false;
        }
        
        for (int i = 1; i < s2.size()+1; i++) {
            dp[0][i-1] && s2[i-1] == s3[i-1] ? dp[0][i] = true : dp[0][i] = false;
        }
        
        for (int i = 1; i < s1.size()+1; i++) {
            for (int j = 1; j < s2.size()+1; j++) {
                dp[i-1][j] && s1[i-1] == s3[i+j-1]? dp[i][j] = true : dp[i][j] = false;
                dp[i][j-1] && s2[j-1] == s3[i+j-1]? dp[i][j] = true : dp[i][j] = (false || dp[i][j]);
            }
        }
        
        bool result =dp[s1.size()][s2.size()];
        for (int i = 0; i < s1.size()+1; i++) {
            delete[] dp[i];
        }
        
        
        
        delete[] dp;
        return result;
        
    }
};

