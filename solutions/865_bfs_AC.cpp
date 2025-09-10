class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), locks = 0, allKeys = 0;
        int bias[5] = {1, 0, -1, 0, 1};
        queue<pair<int, int>> q, next;
        int distance[m][n][1 << 6];
        memset(distance, -1, sizeof(distance));
        int layers = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    q.push({i * 30 + j, 0});
                    distance[i][j][0] = 0;
                }
                if (isupper(grid[i][j])) allKeys |= (1 << (grid[i][j] - 'A'));
            }
        }
        while (!q.empty()) {
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                int curX = cur.first / 30, curY = cur.first % 30, curKeys = cur.second;
                if (curKeys == allKeys) return distance[curX][curY][curKeys];
                for (int k = 0; k < 4; k++) {
                    int newX = curX + bias[k], newY = curY + bias[k + 1];
                    if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] == '#') continue;
                    if (isupper(grid[newX][newY])) {
                        if ((curKeys & (1 << (grid[newX][newY] - 'A'))) == 0) continue;
                    }
                    int keys = curKeys;
                    if (islower(grid[newX][newY])) keys |= (1 << (grid[newX][newY] - 'a'));
                    if (distance[newX][newY][keys] == -1) {
                        distance[newX][newY][keys] = distance[curX][curY][curKeys] + 1;
                        next.push({newX * 30 + newY, keys});
                    }
                }
            }
            swap(q, next);
        }
        return -1;
    }
};