class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> path;
        dfs(n, res, path, 0);
        return res;
    }
    void dfs(int n, vector<vector<string>>& res, vector<int>& path, int col) {
        if (col == n) {
            vector<string> tmp(n, string(n, '.'));
            for (int i = 0; i < n; i++) tmp[i][path[i]] = 'Q';
            res.push_back(tmp);
        }
        for (int r = 0; r < n; r++) {
            if (!conflict(path, r, col)) {
                path.push_back(r);
                dfs(n, res, path, col + 1);
                path.pop_back();
            }
        }
    }
    bool conflict(const vector<int>& path, int row, int col) {
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == row || i + path[i] == col + row || row - col == path[i] - i) return true;
        }
        return false;
    }
};