class Solution {
private: 
    vector<int> dp;
    int helper(const vector<int>& nums, int target) {
        if (dp[target] >= 0) {
            return dp[target];
        }
        int res = 0;
        for (int n : nums) {
            if (target >= n) {
                res += helper(nums, target - n);
            }
        }
        dp[target] = res;
        return res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, -1);
        dp[0] = 1;
        helper(nums, target);
        return dp[target];
    }
};