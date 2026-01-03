class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), bias[5] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) matrix[i][j] = INT_MAX;
                else q.push(make_pair(i, j));
            }
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int r = p.first + bias[k], c = p.second + bias[k + 1];
                if (r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] < matrix[p.first][p.second] + 1) continue;
                q.push(make_pair(r, c));
                matrix[r][c] = matrix[p.first][p.second] + 1;
            }
        }
        return matrix;
    }
};