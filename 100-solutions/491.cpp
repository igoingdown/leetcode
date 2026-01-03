class Solution {
private:
    void dfs(const vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int start) {
        if (start >= nums.size()) return;
        for (int i = start; i < nums.size(); i++) {
            int dup = start;
            while (dup < i && nums[dup] != nums[i]) dup++;
            if (dup != i) continue;
            if (path.size() == 0 || nums[i] >= path.back()) {
                path.push_back(nums[i]);
                if (path.size() > 1) res.push_back(path);
                dfs(nums, res, path, i + 1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res(0, vector<int> (0));
        int n = nums.size();
        if (n < 2) {
            return res;
        }
        vector<int> path;
        dfs(nums, res, path, 0);
        return res;
    }
};