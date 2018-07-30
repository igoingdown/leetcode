class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(res, path, k, n, 1);
        return res;
    }
    
    void dfs(vector<vector<int>> &res, vector<int> &path, int k, int target, int start) {
        if (target == 0 && path.size() == k) {
            res.push_back(path);
            return;
        }
        if (start > 9 || target < 0 || path.size() > k) return;
        if (path.size() == k && target > 0) return;
        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            dfs(res, path, k, target - i, i + 1);
            path.pop_back();
        }
    }
};