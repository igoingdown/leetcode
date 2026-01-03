class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_used[9][9] = {0}, col_used[9][9] = {0}, box_used[9][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1', k = i / 3 * 3 + j / 3; 
                    if (row_used[i][num] || col_used[j][num] || box_used[k][num]) return false;
                    row_used[i][num] = col_used[j][num] = box_used[k][num] = 1;
                }
            }
        }
        return true;
    }
};