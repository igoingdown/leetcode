class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, candidates, 0, target);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>& cand, int cur, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = cur; i < cand.size() && cand[i] <= target; i++) {
            if (i > cur && cand[i] == cand[i - 1]) {
                continue;
            }
            path.push_back(cand[i]);
            dfs(res, path, cand, i + 1, target - cand[i]);
            path.pop_back();
        }
    }
};
