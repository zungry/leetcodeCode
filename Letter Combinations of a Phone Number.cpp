class Solution {
private:
    string num[10];
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        ret.clear();
        creatDict();
        

        //string ans;       
        //ans.clear();
        dfs(digits,0,digits.size(),"",ret);
        return ret;
    }

    void dfs(string &digits,int depth, int maxDep,string ans,vector<string> &ret){
        if(depth == maxDep){
            ret.push_back(ans);
           // ans.clear();
            return;
        }

        for(int i = 0 ; i < num[digits[depth]-'0'].size();i++){
            
            dfs(digits,depth+1,maxDep,ans + num[digits[depth]-'0'][i],ret);
        }
    }

    void creatDict(){
        num[2] = "abc";
        num[3] = "def";
        num[4] = "ghi";
        num[5] = "jkl";
        num[6] = "mno";
        num[7] = "pqrs";
        num[8] = "tuv";
        num[9] = "wxyz";
        
    }
};
