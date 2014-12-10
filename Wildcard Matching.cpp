class Solution{
 public:
      bool isMatch(const char *s,const char *p){
        int slen = strlen(s);
        int plen = strlen(p);
        int maxlen = max(slen,plen);
        
        const char* tmp = p;  
        int cnt = 0;  
        while (*tmp != '\0') if (*(tmp++) != '*') cnt++;  
        if (cnt > slen) return false;  

        bool dp[maxlen+1][maxlen+1];
  
        memset(dp,0,sizeof(dp));
          dp[0][0] = true;
  
          for(int i = 1;i <= plen;i++){
              if(dp[0][i - 1] && p[i - 1] == '*') dp[0][i] = true;
              for(int j = 1;j <= slen;j++){
                  if(p[i - 1] == '*'){
                      dp[j][i] = (dp[j - 1][i] ||dp[j][i-1]);
                  }else if(p[i - 1] == '?' || p[i - 1] == s[j - 1]){
                      dp[j][i] = dp[j-1][i-1];
                  }else{
                      dp[j][i] = false;
                  }
              }
          }
          return dp[slen][plen];
      }
  };      