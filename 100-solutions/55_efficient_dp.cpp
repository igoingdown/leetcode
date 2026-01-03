class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return true;
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] >= 0 && j + nums[j] >= i) {
                    dp[i] = dp[j] + 1; 
                    break;
                } 
            }
        }
        return dp[n - 1] >= 0;
    }
};