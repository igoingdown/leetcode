class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), res = 0;
        vector<int> dp(100000 + 1);
        for (int i = 0; i < n; i++) dp[difficulty[i]] = max(dp[difficulty[i]], profit[i]);
        for (int i = 1; i <= 100000; i++) dp[i] = max(dp[i], dp[i - 1]);
        for (int d : worker) res += dp[d];
        return res;
    }
};