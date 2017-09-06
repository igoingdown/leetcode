class Solution {
public:
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist(board, word.c_str(), i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, const char* w, int r, int c) {
        if (r < 0 || c < 0 || !(r < m) || !(c < n) || (*w != board[r][c]) || (board[r][c] == '\0')) {
            return false;
        }
        if (*(w+1) == '\0') {
            return true;
        }
        
        char tmp = board[r][c];
        board[r][c] = '\0';
        if (exist(board, w + 1, r - 1, c) || exist(board, w + 1, r + 1, c) || exist(board, w + 1, r, c - 1) || 
            exist(board, w + 1, r, c + 1)) {
            return true;
        }
        
        board[r][c] = tmp;
        return false;
    }
    
};