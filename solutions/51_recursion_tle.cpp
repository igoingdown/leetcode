class Solution {
private:
    void dfs(set<set<pair<int, int>>>& paths, set<pair<int, int>>& p, int n) {
        if (p.size() == n) {
            paths.insert(p);
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (check_conflict(p, i, j)) {
                    p.insert(make_pair(i, j));
                    dfs(paths, p, n);
                    p.erase(make_pair(i, j));
                }
            }
        }
    }
    
    bool check_conflict(set<pair<int, int>>& path, int i, int j) {
        for (auto p : path) {
            if ((i == p.first) || (j == p.second) || (p.first + p.second == i + j) || (p.first - p.second == i - j)) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        set<set<pair<int, int>>> paths;
        set<pair<int, int>> path;
        dfs(paths, path, n);
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