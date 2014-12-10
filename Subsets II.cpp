class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
        if(S.size() == 0)
            return ret;
        sort(S.begin(),S.end());
        
        vector<int> temp;
        help(ret,S,temp,0);
        return ret;
    }
    
    void help(vector<vector<int> > &ret,vector<int> &S,vector<int> temp,int index){
        ret.push_back(temp);
        
        for(int i = index;i < S.size();++i){
            if(i!=index && S[i] == S[i-1])
                continue;
            temp.push_back(S[i]);
            help(ret,S,temp,i+1);
            temp.pop_back();
        }
    }
};