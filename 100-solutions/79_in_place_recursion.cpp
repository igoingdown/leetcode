class Solution {
private:
    int m, n, bias[5] = {1, 0, -1, 0, 1};
    bool exist(vector<vector<char>>& board, string& word, int x, int y, int start) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '\0' || board[x][y] != word[start]) return false;
        if (start + 1 == word.size()) return true;
        char tmp = board[x][y];
        board[x][y] = '\0';
        for (int i = 0; i < 4; i++) {
            int newX = x + bias[i], newY = y + bias[i + 1];
            if (exist(board, word, newX, newY, start + 1)) return true;
        }
        board[x][y] = tmp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        m = board.size();
        if (m == 0) return false;
        n = board[0].size();
        if (n == 0) return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};