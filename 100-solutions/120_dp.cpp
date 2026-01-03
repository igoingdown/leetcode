class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(); 
        if (m == 0) return 0;
        vector<int> dp(triangle.back());
        for (int r = m - 1; r > 0; r--) {
            for (int c = 1; c <= r; c++) {
                dp[c - 1] = min(dp[c - 1], dp[c]) + triangle[r - 1][c - 1];
            }
        }
        return dp[0];
    }
};