class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row_used[9][9] = {false}, col_used[9][9] = {false}, box_used[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int num = board[i][j] - '1', k = i / 3 * 3 + j / 3;
                row_used[i][num] = col_used[j][num] = box_used[k][num] = true;
            }
        }
        dfs(board, row_used, col_used, box_used);
    }
    
    bool dfs(vector<vector<char>> &board, bool row_used[9][9], bool col_used[9][9], bool box_used[9][9]) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                
                for (int num = 1; num <= 9; num++) {
                    int n = num - 1, k = i /3 * 3 + j /3;
                    if (row_used[i][n] || col_used[j][n] || box_used[k][n]) {
                        continue;
                    }
                    row_used[i][n] = col_used[j][n] = box_used[k][n] = true;
                    board[i][j] = (char)(num + '0');
                    if (dfs(board, row_used, col_used, box_used)) {
                        return true;
                    }
                    board[i][j] = '.';
                    row_used[i][n] = col_used[j][n] = box_used[k][n] = false;
                }
                return false;
            }
        }
        return true;
    } 
};
