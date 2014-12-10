class Solution{
   public:
        int numDistinct(string S,string T){
         int slen =S.length();
          int tlen = T.length();
        
          int number[slen+1][tlen+1];
          number[0][0] = 1;
          
  
          if(S.size() < T.size()){
              return 0;
          }
  
        for(int i = 1;i <= S.size(); i++){
              number[i][0] = 1;
          }
  
        for(int j = 1;j <= T.size();j++){
              number[0][j] = 0;
          }
  
          //number[0] = 1;
        for(int i = 1;i <= S.size();i++){
              for(int j =1;j <= T.size();j++){
                  if(S[i - 1] == T[j - 1])
                    number[i][j] = number[i - 1][j - 1]+number[i - 1][j];
                  else{
                      number[i][j] = number[i - 1][j];
                  }
              }
          }
        return number[slen][tlen];                                                                                                                                                                         
  
      }
  };
