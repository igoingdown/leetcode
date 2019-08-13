class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), res = 0, n;
        if (m == 0) return res;
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    if (i == 0 || !grid[i-1][j]) res++;
                    if (i == m - 1 || !grid[i+1][j]) res++;
                    if (j == 0 || !grid[i][j - 1]) res++;
                    if (j == n - 1 || !grid[i][j + 1]) res++;
                }
            }
        }
        return res;
    }
};
