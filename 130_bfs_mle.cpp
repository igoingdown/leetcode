class Solution {
private:
    int m, n;
    int bias[5] = {1, 0, -1, 0, 1};
    void bfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            board[x][y] = 'F';
            for (int k = 0; k < 4; k++) {
                int new_x = x + bias[k], new_y = y + bias[k + 1];
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && board[new_x][new_y] == 'O') {
                    q.push(make_pair(new_x, new_y));
                }
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            bfs(board, i, 0);
            bfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            bfs(board, 0, j);
            bfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = (board[i][j] == 'F' ? 'O' : 'X');
            }
        }
    }
};