class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, tmp, nums);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums) {
        if (nums.size() == tmp.size()) {
            res.push_back(tmp);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (count(tmp.begin(), tmp.end(), nums[i]) == count(nums.begin(), nums.end(), nums[i])) {
                    continue;
                } else if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                } else {
                    tmp.push_back(nums[i]);
                    backtrack(res, tmp, nums);
                    tmp.pop_back();
                }
            }
        }
    }
};