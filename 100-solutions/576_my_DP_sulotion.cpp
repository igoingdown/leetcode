class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N < 1) {
            return 0;
        }
        vector< vector< vector<int> > > dp(N, vector< vector<int> > (m, vector<int> (n, 0)));
        for (int l = 0; l < N; l++) {
            for (int k = 0; k < m; k++) {
                dp[l][k][0]++;
                dp[l][k][n - 1]++;
            }
            for (int k = 0; k < n; k++) {
                dp[l][0][k]++;
                dp[l][m - 1][k]++;
            }
        }
        int pBias[4] = {1, -1, 0, 0};
        int qBias[4] = {0, 0, 1, -1};
        for (int k = 1; k < N; k++) {
            for (int p = 0; p < m; p++) {
                for (int q = 0; q < n; q++) {
                    for (int b = 0; b < 4; b++) {
                        int newP = p + pBias[b], newQ = q + qBias[b];
                        if (newP < m && newP >= 0 && newQ >= 0 && newQ < n) {
                            dp[k][p][q] += (dp[k - 1][newP][newQ] % 1000000007);
                            dp[k][p][q] %= 1000000007;
                        }
                    }
                }
            }
        }
        return dp[N - 1][i][j];
    }
};