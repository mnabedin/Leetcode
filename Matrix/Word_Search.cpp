class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int index) {
        if(index == word.size()) 
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) 
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        index++;
        bool ret = dfs(board, word, i + 1, j, index) || dfs(board, word, i, j + 1, index) || dfs(board, word, i - 1, j, index) || dfs(board, word, i, j - 1, index);
        board[i][j] = c;
        return ret;
    }
};