class Solution{                                                                                                                                                                                              
public:
    string longestCommonPrefix(vector<string> &strs){
        int len = strs.size();
        if(len ==0)
          return "";
        string ret = strs[0]; 

        for(int i = 1; i < len; i++ ){
            if(ret.size() == 0 || strs[i].size()==0)
              return "";
            int lengthofString = min(strs[i].length(),ret.size());
            int j;
            for(j = 0 ;j < lengthofString; j++){
                if(ret[j] != strs[i][j])
                  break;
            }   
            ret = ret.substr(0,j);
        }   
        return ret;
    }   
};
