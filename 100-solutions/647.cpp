class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n < 1) {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        vector<int> row(n, 0);
        vector<vector<int> > dp(n, row);
        // memset(dp, 0, sizeof(int));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[0] == s[j]) {
                    if (j > 1 && dp[1][j - 1]) {
                        dp[0][j] = 1;
                    }
                    if (j < 2) {
                        dp[0][j] = 1;
                    }
                }
            }
            for (int j = 0; j <= i; j++) {
                if (s[j] == s[i]) {
                    if (i - 1 > j && dp[j + 1][i - 1]) {
                        dp[j][i] = 1;
                    }
                    if (i - j < 2) {
                        dp[j][i] = 1;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                res += dp[i][j];
            }
        }
        return res;
    }
};