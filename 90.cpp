class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, tmp, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int s) {
        res.push_back(tmp);
        for (int i = s; i < nums.size(); i++) {
            if (i > s && nums[i] == nums[i - 1]) {
                continue;
            } else {
                tmp.push_back(nums[i]);
                backtrack(res, tmp, nums, i + 1);
                tmp.pop_back();
            }
        }
    }
};