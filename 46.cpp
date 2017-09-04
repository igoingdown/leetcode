class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrace(res, tmp, nums);
        return res;
    }
    
    void backtrace(vector<vector<int>> &res, vector<int>& tmp, vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                auto iter = find(tmp.begin(), tmp.end(), nums[i]);
                if (iter != tmp.end()) {
                    continue;
                } else {
                    tmp.push_back(nums[i]);
                    backtrace(res, tmp, nums);
                    tmp.pop_back();
                }
            }
        }
    }
};