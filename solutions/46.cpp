class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        map<int, int> visit;
        dfs(nums, res, path, visit);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, map<int, int>& visit) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int n : nums) {
            if (!visit[n] > 0) {
                path.push_back(n);
                visit[n] = 1;
                dfs(nums, res, path, visit);
                path.pop_back();
                visit[n] = 0;
            }
        }
    }
};