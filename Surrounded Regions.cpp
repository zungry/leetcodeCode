class Solution {
private:
	int rows;
	int cols;
public:
	void dfs(int row, int col,vector<vector<char> >& board)
	{
		if(row < 0 || row >= rows || col < 0 || col >= cols) return;
		if(board[row][col] != 'O') return;
		board[row][col] = '+';
		dfs(row - 1, col, board);//up
		dfs(row, col + 1, board);//right
		dfs(row + 1, col, board);//down
		dfs(row, col - 1, board);//left
	}
	void solve(vector<vector<char> > &board)
	{
		if(board.size() == 0 || board[0].size() == 0)
			return;
		 rows = board.size();
		 cols = board[0].size();
		 for(int i = 0; i < rows; ++i){
			 dfs(i, 0, board);
			 dfs(i, cols - 1, board);
		 }
		 for (int j = 0; j < cols; ++j)
		 {
			 dfs(0, j, board);
			 dfs(rows - 1, j, board);
		 }
		 for(int i = 0; i < rows; ++i)
			 for (int j = 0; j < cols; ++j)
			 {
				if(board[i][j] == 'O')
					board[i][j] = 'X';
				else if(board[i][j] == '+')
					 board[i][j] = 'O';		 
			 }	 
	}
};