class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> cur(n, grid[0][0]);
        for (int i = 1; i < n; i++) {
            cur[i] = cur[i - 1] + grid[i][0];
        }
        for (int j = 1; j < m; j++) {
            cur[0] += grid[0][j];
            for (int i = 1; i < n; i++) {
                cur[i] = min(cur[i], cur[i - 1]) + grid[i][j];
            }
        }
        return cur[n - 1];
    }
};
