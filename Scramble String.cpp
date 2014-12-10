class Solution {
public:
    bool isScramble(string s1, string s2) {
        size_t len1 = s1.size();
        size_t len2 = s2.size();
        
        if (len1 != len2) {
            return false;
        }
        
        if (len1 == 0) {
            return true;
        }
        
        if (len1 == 1) {
            return s1 == s2;
        }
        
        bool dp[len1+1][len1+1][len1+1];
        memset(dp, false, sizeof(dp));
        
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        
        for(int k = 2;k <= len1;++k)
            for (int i = 0; i <= len1 - k; ++i) {
                for (int j = 0; j <= len1 - k; ++j) {
                    for (int l = 1; l < k; ++l) {
                        if ((dp[l][i][j] && dp[k - l][i+l][j+l]) || (dp[l][i][j+k-l] && dp[k-l][i+l][j])) {
                            dp[k][i][j]=true;
                            break;
                        }
                    }
                }
            }
        return dp[len1][0][0];
    }
    
    
    
};