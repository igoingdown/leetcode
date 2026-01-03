class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, res, path, 0, target);
        return res;
    }
    
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& path, int start, int target) {
        if (target == 0) res.push_back(path);
        if (target <= 0) return;
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            dfs(candidates, res, path, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }
};