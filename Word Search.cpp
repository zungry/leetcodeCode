class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.length() == 0){
            return false;
        }

        
        vector<vector<bool> > visited;
        visited.resize(board.size());
        for (int i = 0; i < board.size(); ++i) {
            visited[i].resize(board[i].size());
        }
        
        for(int i = 0;i < board.size();i++){
            for (int j = 0; j < board[0].size(); j++) {
                visited[i][j] = false;
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (word.length() == 1 || search(board,i,j,word.substr(1),visited)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
    
    bool search(vector<vector<char> > &board,int i,int j,string word, vector<vector<bool> > &visited){
        if (word.length() == 0) {
            return true;
        }
        
        int direction[][2]  = {{-1,0},{1,0},{0,-1},{0,1}};
        
        for(int k = 0;k < 4;++k){
            int ii = i + direction[k][0];
            int jj = j + direction[k][1];
            
            if(ii >= 0 && ii < board.size() && jj >= 0 && jj < board[i].size() && board[ii][jj] == word[0] && visited[ii][jj] == false){
                visited[ii][jj] = true;
                if(word.length() == 1 || search(board, ii, jj, word.substr(1), visited)){
                    return true;
                }
                visited[ii][jj] = false;
            }
        }
        return false;
    }
};