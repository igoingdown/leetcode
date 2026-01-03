class Solution {
private:
    int m, n;
    int bias[5] = {1, 0, -1, 0, 1};
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        board[i][j] = 'F';
        for (int k = 0; k < 4; k++) dfs(board, i + bias[k], j + bias[k + 1]);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = (board[i][j] == 'F' ? 'O' : 'X');
            }
        }
    }
};