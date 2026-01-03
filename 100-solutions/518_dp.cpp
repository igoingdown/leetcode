class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        if (coins.size() == 0) return 0;
        vector<int> dp(amount + 1, 0); dp[0] = 1;
        // 外循环控制可以使用的硬币，每次新加入一种面值的硬币
        // 内循环按新加入的硬币的面值爬楼梯，因为这样可以确保中间爬楼梯的方式唯一，所以可以放心使用。
        // 我自己写的时候就写反了，导致存在大量的重复解
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) dp[i] += dp[i - coin];
        }
        return dp[amount];
    }
};