class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row_used[9][9] = {false}, col_used[9][9] = {false}, box_used[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1', k = i / 3 * 3 + j / 3;
                    row_used[i][num] = col_used[j][num] = box_used[k][num] = true;
                }
            }
        }
        dfs(board, row_used, col_used, box_used);
    }
    
    bool dfs(vector<vector<char>>& board, bool row_used[9][9], bool col_used[9][9], bool box_used[9][9]) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int num = 1; num <= 9; num++) {
                        int k = i / 3 * 3 + j / 3;
                        if (row_used[i][num - 1] || col_used[j][num - 1] || box_used[k][num - 1]) continue;
                        board[i][j] = (char)(num + '0');
                        row_used[i][num - 1] = col_used[j][num - 1] = box_used[k][num - 1] = true;
                        if (dfs(board, row_used, col_used, box_used)) return true;
                        board[i][j] = '.';
                        row_used[i][num - 1] = col_used[j][num - 1] = box_used[k][num - 1] = false;
                    }
                    return false;
                }
            }
        }
        return true;
    }
};