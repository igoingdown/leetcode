class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n;
        if (m == 0) return res;
        n = matrix[0].size();
        if (n == 0) return res;
        int i = 0, j = 0;
        for (int i = 0; i < n - i && i < m - i; i++) {
            for (int r = i, c = i; c < n - i; c++) res.push_back(matrix[r][c]);
            for (int r = i + 1, c = n - i - 1; r < m - i; r++) res.push_back(matrix[r][c]);
            for (int r = m - i - 1, c = n - i - 2; r > i && c >= i; c--) res.push_back(matrix[r][c]);
            for (int r = m - i - 2, c = i; r > i && c < n - i - 1; r--) res.push_back(matrix[r][c]);
        }
        return res;
    }
};