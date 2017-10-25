class Solution {
private:
    void dfs(set<set<pair<int, int>>>& paths, set<pair<int, int>>& p, int n) {
        if (p.size() == n) {
            paths.insert(p);
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!conflict(p, i, j)) {
                    p.insert(make_pair(i, j));
                    dfs(paths, p, n);
                    p.erase(make_pair(i, j));
                }
            }
        }
    }
    bool conflict(set<pair<int, int>>& p, int i, int j) {
        for (auto node : p) {
            if (node.first == i || node.second == j || node.first + node.second == i + j || node.first - node.second == i - j) {
                return true;
            }
        }
        return false;
    }
public:
    int totalNQueens(int n) {
        set<set<pair<int, int>>> paths;
        set<pair<int, int>> path;
        dfs(paths, path, n);
        return paths.size();
    }
};