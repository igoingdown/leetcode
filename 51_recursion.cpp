class Solution {
private:
    void dfs(set<set<pair<int, int>>>& paths, set<pair<int, int>>& p, int row, int n) {
        if (row == n) {
            paths.insert(p);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (!conflict(p, row, col)) {
                p.insert(make_pair(row, col));
                dfs(paths, p, row + 1, n);
                p.erase(make_pair(row, col));
            }
        }
    }
    
    bool conflict(set<pair<int, int>>& path, int i, int j) {
        for (auto p : path) {
            if ((i == p.first) || (j == p.second) || (p.first + p.second == i + j) || (p.first - p.second == i - j)) {
                return true;
            }
        }
        return false;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        set<set<pair<int, int>>> paths;
        set<pair<int, int>> path;
        dfs(paths, path, 0, n);
        vector<vector<string>> res;
        for (auto p : paths) {
            vector<string> solution(n, string(n, '.'));
            for (auto node : p) {
                solution[node.first][node.second] = 'Q';
            }
            res.push_back(solution);
        }
        return res;
    }
};