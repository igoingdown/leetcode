class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size(), res = 0;
        vector<int> dp(len, 1);
        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) dp[i] += dp[i - 1];
        }
        res += len > 0 ? dp.back() : 0;
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && dp[i] <= dp[i + 1]) dp[i] = dp[i + 1] + 1;
            res += dp[i];
        }
        return res;
    }
};