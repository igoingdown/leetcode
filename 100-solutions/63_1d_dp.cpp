class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n;
        if (m == 0) return 0;
        n = obstacleGrid[0].size();
        if (n == 0) return 0;
        vector<int> dp(m, 0);
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0) dp[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1) dp[0] = 0;
            for (int i = 1; i < m; i++) dp[i] = obstacleGrid[i][j] == 1 ? 0 : dp[i] + dp[i - 1];
        }
        return dp[m - 1];
    }
};