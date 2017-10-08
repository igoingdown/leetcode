class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); // grid is m * n.
        vector<int> bias = {1, 0, -1, 0, 1};
        set<vector<int>> islands; // set[i] = (r - base_r) * 100 + (c - base_c)
        for (int  i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int tmp = 1;
                    queue<int> q; // q[i] = 100 * row + col;
                    q.push(i * 100 + j);
                    grid[i][j] = 0;
                    vector<int> island;
                    island.push_back(0);
                    while (!q.empty()) {
                        int head = q.front();
                        q.pop();
                        int r = head / 100, c = head % 100;
                        for (int k = 0; k < 4; k++) {
                            int new_r = r + bias[k], new_c = c + bias[k + 1];
                            if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && grid[new_r][new_c]) {
                                q.push(100 * new_r + new_c);
                                grid[new_r][new_c] = 0;
                                island.push_back((new_r - i) * 100 + (new_c - j));
                            }
                        }
                    }
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
};