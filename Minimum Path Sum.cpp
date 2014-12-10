class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        
        int m = grid[0].size();
        
        vector<vector<int> >f(n+1,vector<int>(m+1,INT_MAX));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(i == 1 && j == 1)
                    f[i][j] = grid[i-1][j-1];
                else {
                    f[i][j] = min(f[i-1][j],f[i][j-1])+grid[i-1][j-1];
                }
            }
        }
        return f[n][m];
    }
};