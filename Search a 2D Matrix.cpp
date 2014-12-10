class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        if(matrix.size() == 0)
            return false;
        bool found = false;
        
        while(row < matrix.size() && col >= 0){
            if(matrix[row][col] == target){
                found = true;
                break;
            }else if(matrix[row][col] < target){
                ++row;
            }else{
                --col;
            }
        }
        return found;
    }
};