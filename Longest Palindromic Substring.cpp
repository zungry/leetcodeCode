class Solution {
public:
    string longestPalindrome(string s) {
        const int len = s.size();
        if(len <= 1)return s;
        bool dp[len][len];//dp[i][j]表示s[i..j]是否是回文
        memset(dp, 0, sizeof(dp));
        int resLeft = 0, resRight = 0;
        dp[0][0] = true;
        for(int i = 1; i < len; i++)
        {
            dp[i][i] = true;
            dp[i][i-1] = true;//这个初始化容易忽略，当k=2时要用到
        }
        for(int k = 2; k <= len; k++)//枚举子串长度
            for(int i = 0; i <= len-k; i++)//枚举子串起始位置
            {
                if(s[i] == s[i+k-1] && dp[i+1][i+k-2])
                {
                    dp[i][i+k-1] = true;
                    if(resRight-resLeft+1 < k)
                    {
                        resLeft = i;
                        resRight = i+k-1;
                    }
                }
            }
        return s.substr(resLeft, resRight-resLeft+1);
    }
};
