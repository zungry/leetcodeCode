class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;

        if(numRows <= 0)
            return ret;
                
        for(int i = 0; i < numRows; i++){  
            vector<int> level;
            if(i == 0)
                level.push_back(1);
            else{
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i)
                    level.push_back(1);
                else
                    level.push_back(ret[i-1][j-1]+ret[i-1][j]);
            }
            }
            ret.push_back(level);
        }
        return ret;
    };
};