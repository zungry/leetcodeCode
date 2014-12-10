class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int xlen = matrix.size();
        if(xlen == 0)
            return;
        int ylen = matrix[0].size();
        
        for(int i = 0; i < xlen - 1 ;i++){
            for(int j = 0;j < ylen - i;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[xlen - j - 1][ylen - i - 1];
                matrix[xlen - j - 1][ylen - i - 1] = tmp;
            }
        }
        
        for(int i = 0;i < xlen/2;i++){
            for(int j = 0;j < ylen;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[xlen - i - 1][j];
                matrix[xlen - i - 1][j] = tmp;
            }
        }
    }
};