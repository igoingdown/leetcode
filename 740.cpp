class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> scores(10001, 0), dp(10001, 0);
        for (int n : nums) scores[n] += n;
        dp[1] = scores[1];
        for (int i = 2; i < 10001; i++) dp[i] = max(dp[i - 1], dp[i - 2] + scores[i]);
        return dp[10000];
    }
};