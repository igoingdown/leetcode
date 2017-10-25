class Solution {
private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (valid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }  
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool valid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // 检查同行的每一个元素
            if (board[row][i] == c && board[row][i] != '.') return false;
            // 检查同列的每一个元素
            if (board[i][col] == c && board[i][col] != '.') return false;
            // 检查同一小方格中的每一个元素
            if (c == board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] && board[(row / 3) * 3 + i/ 3][(col / 3) * 3 + i % 3] != '.') return false;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        solve(board);
    }
    
    
    
    
};