class NumMatrix {
private:
    vector< vector<int> > sum;
    int m = 0, n = 0; //m * n.
public:
    NumMatrix(vector<vector<int>> matrix) {
        m = matrix.size();
        if (m) {
            n = matrix[0].size();  // m * n
            sum.resize(m, vector<int>(n, 0));
            sum[0][0] = matrix[0][0];
            for (int i = 1; i < m; i++) {
                sum[i][0] = matrix[i][0] + sum[i - 1][0];
            }
            for (int j = 1; j < n; j++) {
                sum[0][j] = matrix[0][j] + sum[0][j - 1];
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + matrix[i][j] - sum[i - 1][j - 1];
                }
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 < m && row2 < m && col1 < n && col2 < n) {
            if (!row1 && !col1) {
                return sum[row2][col2];
            } else if (!row1 && col1) {
                return sum[row2][col2] - sum[row2][col1 - 1];
            } else if (row1 && !col1) {
                return sum[row2][col2] - sum[row1 - 1][col2];
            } else {
                return sum[row2][col2] - sum[row2][col1 - 1] - sum[row1 - 1][col2] + sum[row1 - 1][col1- 1];
            }
        }
        return 0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */