class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[j] >= 0 && j + nums[j] >= i) {
                    dp[i] = dp[j] + 1; break;
                }
            }
        }
        return dp[n - 1];
    }
};