class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    fill(i, j, board[i][j] - '0');
                }
            }
        }
        
        solver(board,0);
        
        
    }
    
    
    bool solver(vector<vector<char> > &board, int index){
        if (index > 80) {
            return true;
        }
        
        int row = index/9;
        int col = index - 9 * row;
        
        
        if (board[row][col] != '.') {
            return solver(board,index+1);
        }
        
        for (int i = '1'; i <= '9'; i++) {
           // board[row][col] = '0'+i;
            if (isValid(row ,col,i - '0')) {
                board[row][col] = i;
                fill(row, col, i - '0');
                if (solver(board, index+1)) {
                    return true;
                }
                clear(row,col,i - '0');
            }
            board[row][col] = '.';
        }
        
        return false;
    };
    
    bool isValid(int row, int col, int val)
    {
        if(rowValid[row][val] == 0 &&
           colValid[col][val] == 0 &&
           subBoardValid[row/3*3+col/3][val] == 0)
            return true;
        return false;
    }
    
    void fill(int row, int col, int val)
    {
        rowValid[row][val] = 1;
        colValid[col][val] = 1;
        subBoardValid[row/3*3+col/3][val] = 1;
    }
    
    void clear(int row,int col,int val){
        rowValid[row][val] = 0;
        colValid[col][val] = 0;
        subBoardValid[row/3*3+col/3][val] = 0;
    }
    
private:
    int rowValid[9][10];
    int colValid[9][10];
    int subBoardValid[9][10];
};