class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> path;
        dfs(res, n, path, 0);
        return res;
    }
    void dfs(int& res, int n, vector<int>& path, int col) {
        if (col == n) res+= 1;
        for (int r = 0; r < n; r++) {
            if (!conflict(path, r, col)) {
                path.push_back(r);
                dfs(res, n, path, col + 1);
                path.pop_back();
            }
        }
    }
    bool conflict(const vector<int>& path, int row, int col) {
        for (int i = 0; i < path.size(); i++) if (path[i] == row || i - path[i] == col - row || i + path[i] == row + col) return true;
        return false;
    }
};