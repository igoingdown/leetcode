class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        long long target = sum >> 1;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num: nums) {
            for (long long i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};