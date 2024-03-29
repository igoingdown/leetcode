class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, 1, n, k);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& path, int start, int n, int k) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(res, path, i + 1, n, k);
            path.pop_back();
        }
    }
};