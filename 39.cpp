class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, candidates, path, 0, target);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& cand, vector<int>& path, int cur, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = cur; i < cand.size() && cand[i] <= target; i++) {
            path.push_back(cand[i]);
            dfs(res, cand, path, i, target - cand[i]);
            path.pop_back();
        }
    }
};
