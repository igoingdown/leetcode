class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MAX = amount + 1;
        vector<int> dp(MAX, MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int n : coins) {
                if (i >= n) {
                    dp[i] = min(dp[i], 1 + dp[i - n]);
                }
            }
        }
        return dp[amount] < MAX ? dp[amount] : -1;
    }
};