class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n) return uniquePaths(n, m);
        vector<int> dp(m, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) dp[j] += dp[j - 1];
        }
        return dp[m - 1];
    }
};