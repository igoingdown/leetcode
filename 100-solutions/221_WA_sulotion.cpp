class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector< vector<int> > dp(n, vector<int>(m, 0));
        int res = 0;
        cout << "bb" << endl;
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0] - '0';
            res = max(res, dp[i][0]);
        }
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j] - '0';
            res = max(res, dp[0][j]);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (dp[i - 1][j - 1]) {
                    int s = sqrt(dp[i - 1][j - 1]);
                    bool flag = true;
                    for (int k = 0; k <= s; k++) {
                        if (!(matrix[i][j - k] - '0' && matrix[i - k][j] - '0')) {
                            flag = false;
                            break;
                        }
                    } 
                    if (!flag) {
                        res = max(res, dp[i - 1][j - 1]);
                        continue;
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + 2 * s - 1;
                        res = max(res, dp[i][j]);
                    }
                }
                
            }
        }
        return res;
    }
};