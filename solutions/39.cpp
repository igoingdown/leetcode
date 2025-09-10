class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, candidates, target, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>& can, int target, int start) {
        if (start >= can.size() || target < 0) return;
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < can.size(); i++) {
            path.push_back(can[i]);
            dfs(res, path, can, target - can[i], i);
            path.pop_back();
        }
    }
};