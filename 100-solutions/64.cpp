class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        vector<int> dp(m);
        dp[0] = grid[0][0];
        for (int i = 1; i < m; i++) dp[i] = dp[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) {
            dp[0] += grid[0][j];
            for (int i = 1; i < m; i++) dp[i] = min(dp[i], dp[i - 1]) + grid[i][j];
        }
        return dp[m - 1];
    }
};