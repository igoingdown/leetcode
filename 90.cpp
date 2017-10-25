class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int start) {
        if (start == nums.size()) return;
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            dfs(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int> (0));
        int s = nums.size();
        if (!s) return res;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        dfs(res, tmp, nums, 0);
        return res;
    }
};