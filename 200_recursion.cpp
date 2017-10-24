class Solution {
private:
    int idx[5] = {1, 0, -1, 0, 1}, m, n;
    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            int new_i = i + idx[k], new_j = j + idx[k + 1];
            if (new_i >= 0 && new_i < m && new_j >=0 && new_j < n && grid[new_i][new_j] == '1') {
                dfs(new_i, new_j, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    res++;
                }
                
            }
        }
        return res;
    }
};