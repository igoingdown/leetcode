class Solution {
public:
    // O(N^2)
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n;
        if (m == 0) return true;
        n = matrix[0].size();
        if (n == 0) return true;
        for (int i = m - 1; i >= 0; i--) {
            int x = matrix[i][0];
            for (int j = 0; i + j < m && j < n; j++) {
                if (matrix[i + j][j] != x) return false;
            }
        }
        for (int j = n - 1; j > 0; j--) {
            int x = matrix[0][j];
            for (int i = 0; i < m && i + j < n; i++) {
                if (matrix[i][i + j] != x) return false;
            }
        }
        return true;
    }
};
