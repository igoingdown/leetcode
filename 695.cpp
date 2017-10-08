class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size(); // grid is m * n.
        vector<int> bias_r = {0, 0, 1, -1};
        vector<int> bias_c = {1, -1, 0, 0};
        for (int  i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int tmp = 1;
                    queue<int> q; // q[i] = 100 * row + col;
                    q.push(i * 100 + j);
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        int head = q.front();
                        q.pop();
                        int r = head / 100, c = head % 100;
                        for (int k = 0; k < 4; k++) {
                            int new_r = r + bias_r[k], new_c = c + bias_c[k];
                            if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && grid[new_r][new_c]) {
                                q.push(100 * new_r + new_c);
                                tmp++;
                                grid[new_r][new_c] = 0;
                            }
                        }

                    }
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};