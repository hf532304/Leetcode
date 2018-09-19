class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int pos){
        if(pos == word.length())
            return true;
        if(i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1)
            return false;
        bool res;
        if(word[pos] == board[i][j]){
            char tmp = board[i][j];
            board[i][j] = 0;            //avoid duplicating same cell
            res = (dfs(board, i+1, j, word, pos + 1) ||        //if one path is true, return true
             dfs(board, i, j+1, word, pos + 1) ||
             dfs(board, i-1, j, word, pos + 1) ||
             dfs(board, i, j-1, word, pos + 1));
            if(!res)    board[i][j] = tmp;
            return res;
                
        }
        else    return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        vector<vector<char>> new_Board(board); // not to change the input
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(new_Board[i][j] == word[0])
                    res = (res || dfs(board, i, j, word, 0));
            }
        }
        return res;
    }
};