class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        map<int, int> f;
        for (auto n : nums) f[n]++;
        sort(nums.begin(), nums.end());
        dfs(res, path, f, nums);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> &path, map<int, int> &f, vector<int> &nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (auto iter = f.begin(); iter != f.end(); iter++) {
            if (iter->second > 0) {
                iter->second--;
                path.push_back(iter->first);
                dfs(res, path, f, nums);
                iter->second++;
                path.pop_back();
            }
        }
    }
};