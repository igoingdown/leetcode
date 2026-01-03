class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> nums;
        for (int i = 0; i < 9; i++) {
            nums.clear(); nums.resize(9, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (nums[board[i][j] - '1'] > 0) return false;
                    nums[board[i][j] - '1']++;
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            nums.clear(); nums.resize(9, 0);
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (nums[board[i][j] - '1'] > 0) return false;
                    nums[board[i][j] - '1']++;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                nums.clear(); nums.resize(9, 0);
                for (int k = 0; k < 9; k++) {
                    int i_bias = k / 3, j_bias = k % 3;
                    if (board[i * 3 + i_bias][j * 3 + j_bias] != '.') {
                        if (nums[board[i * 3 + i_bias][j * 3 + j_bias] - '1'] > 0) return false;
                        nums[board[i * 3 + i_bias][j * 3 + j_bias] - '1']++;
                    }
                }
            }
        }
        return true;
    }
};