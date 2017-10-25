class Solution {
private:
    void dfs(int& paths, set<pair<int, int>>& p, int row, int n) {
        if (p.size() == n) {
            paths++;
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
        int paths = 0;
        set<pair<int, int>> path;
        dfs(paths, path, 0, n);
        return paths;
    }
};