class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        int ret = INT_MAX;
        if(triangle.size() == 0)
            return 0;
            
        vector<int> sum(triangle[m - 1].size());
        
        sum[0] = triangle[0][0];
        for(int i = 1; i < m; i++){
            for(int j = triangle[i].size() - 1; j >= 0 ; j--)
                if(j == 0)
                    sum[j] = sum[j] + triangle[i][j];
                else if(j == triangle[i].size() - 1)
                    sum[j] = sum[j - 1] + triangle[i][j];
                else
                    sum[j] = min(sum[j],sum[j - 1]) + triangle[i][j];
        }

        for(int i = 0 ; i < triangle[m - 1].size(); i++){
            ret = min(ret,sum[i]);
        }

        return ret;
    }
};