class Solution{
  public:
      vector<string> generateParenthesis(int n){ 
          if(n <= 0)
            return vector<string>();
              
          vector<string> ret;
          generateParenthesisCore(ret,n,n,n,"");
          return ret;                                                                                                                                                                                        
      }
  
      void generateParenthesisCore(vector<string> &ret,int n,int left,int right,string s){ 
          if(left == 0 && right == 0){ 
              ret.push_back(s);
              return;
          }
  
          if(left > 0){ 
              string stmp = s + "(";
              generateParenthesisCore(ret,n,left-1,right,stmp);
              s = stmp.substr(0,stmp.size()-1);
          }
  
          if(left < right){
              string stmp = s + ")";
              generateParenthesisCore(ret,n,left,right-1,stmp);
              s = stmp.substr(0,stmp.size()-1);
          }   
      }   
};
