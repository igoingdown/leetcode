class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(10000 + 1);
        vector<int> res(10000 + 1);
        for (int n : nums) {
            dp[n]++;
        }
        res[1] = dp[1];
        for (int i = 2; i < 10001; i++) {
            res[i] = max(res[i - 2] + dp[i] * i, res[i - 1]);
        }
        return res[10000];
    }
};