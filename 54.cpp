class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return vector<int>(0);
        }
        if (matrix[0].size() == 0) {
            return vector<int>(0);
        }
        int i = 0, j = 0, k = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        while (k < m * n) {
            int cur = j;
            while (cur <= n - j - 1) {
                res[k++] = matrix[i][cur++];
            }
            cur = i + 1;
            while (cur <= m - i - 1) {
                res[k++] = matrix[cur++][n - j - 1];
            }
            cur = n - j - 2;
            if (i != m - i - 1) {
                while (cur >= j) {
                    res[k++] = matrix[m - i - 1][cur--];
                }
            }
            cur = m - i - 2;
            if (j != n - j - 1) {
                while (cur > i) {
                    res[k++] = matrix[cur--][j];
                }
            }
            i++;
            j++;
        }
        return res;
    }
};
