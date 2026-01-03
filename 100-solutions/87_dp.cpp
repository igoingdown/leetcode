class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = s1[i] == s2[j];
            }
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                for (int j = 0; j < n - l + 1; j++) {
                    for (int k = 1; k < l; k++) {
                        if (dp[i][j][l]) break;
                        dp[i][j][l] = (dp[i][j][k] && dp[i + k][j + k][l - k]) || 
                            (dp[i][j + l - k][k] && dp[i + k][j][l - k]);
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};