class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        long long target = sum >> 1;
        int n = nums.size();
        vector<bool> row(target + 1, false);
        vector<vector<bool>> dp(n+1, row);
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int k = 1; k < n + 1; k++) { 
            for (long long i = target; i >= nums[k - 1]; i--) {
                dp[k][i] = dp[k-1][i];
                dp[k][i] = dp[k][i] || dp[k -1][i - nums[k - 1]];
            }
        }
        return dp[n][target];
    }
};