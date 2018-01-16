class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        map<int, int> freq;
        for (auto n : nums) freq[n]++;
        sort(nums.begin(), nums.end());
        dfs(nums, res, path, freq);
        return res;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, map<int, int>& freq) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (count(path.begin(), path.end(), nums[i]) < freq[nums[i]] && !(i > 0 && nums[i] == nums[i - 1])) {
                path.push_back(nums[i]);
                dfs(nums, res, path, freq);
                path.pop_back();
            }
        }
    }
};