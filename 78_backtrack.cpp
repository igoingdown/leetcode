class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrace(res, tmp, nums, 0);
        return res;
    }
    
    void backtrace(vector<vector<int>> &res, vector<int> &tmp, vector<int>& nums, int b) {
        res.push_back(tmp);
        for (int i = b; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrace(res, tmp, nums, i+1);
            tmp.pop_back();
        }
    }
};