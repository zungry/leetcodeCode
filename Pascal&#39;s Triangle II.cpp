class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0)
            return vector<int>();
        
        int ret[rowIndex + 1];
        
        if(rowIndex == 0)
        {
            vector<int> ans;
            ans.push_back(1);
            return ans;
        }
        
        for(int i = 0; i <= rowIndex ; i++){
            if(i == 0){
                ret[0] = 1;
                // tmp[0] = 1;
            }
            else {
                for(int j = i; j >= 0; j--){
                    if(j == 0 || j == i)
                        ret[j] = 1;
                    else{
                        ret[j] = ret[j - 1] + ret[j];
                    }
                }
            }
        }
        vector<int> ans(ret,ret + rowIndex + 1);
        return ans;
    }
};
