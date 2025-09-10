class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return true;
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] < 0) continue;
            for (int j = 1; j <= nums[i] && i + j < n; j++) dp[i + j] = dp[i + j] == -1 ? dp[i] + 1 : min(dp[i + j], dp[i + 1]);
        }
        return dp[n - 1] >= 0;
    }
};