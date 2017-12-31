class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int bias[5] = {0, 1, 0, -1, 0};
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                bfs(matrix, i, j, res, bias);
            }
        }
        return res;
    }
    
    void bfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& res, int* bias) {
        queue<pair<int, int>> q, next;
        q.push(make_pair(i, j));
        int layer = 0;
        while (!q.empty()) {
            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                if (!matrix[p.first][p.second]) {
                    res[i][j] = layer;
                    return;
                } else {
                    for (int k = 0; k < 4; k++) {
                        int r = p.first + bias[k], c = p.second + bias[k + 1];
                        if (r >= 0 && c >= 0 && r < matrix.size() && c < matrix[0].size()) next.push(make_pair(r, c));
                    }
                }
            }
            swap(q, next);
            layer++;
        }
    }
};