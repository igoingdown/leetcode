class Solution {
private:
    int m, n;
    int bias[5] = {1, 0, -1, 0, 1};
    bool exist(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int row, int col, int start) {
        if (start == word.size() || row < 0 || row >= m || col < 0 || col >= n || word[start] != board[row][col] || visited[row][col]) return false;
        if (start + 1 == word.size()) return true;
        visited[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int p = row + bias[i], q = col + bias[i + 1];
            if (exist(board, word, visited, p, q, start + 1)) return true;
        }
        visited[row][col] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        m = board.size();
        if (m == 0) return false;
        n = board[0].size();
        if (n == 0) return false;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist(board, word, visited, i, j, 0)) return true;
            }
        }
        return false;
    }
};