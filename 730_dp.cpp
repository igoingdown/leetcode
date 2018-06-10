class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size(), res = 0;
        if (n < 2) return n; 
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        long long num_mod = 1000000007;
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 1; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                if (S[i] == S[j]) {
                    dp[i][j] = 2 * dp[i + 1][j - 1];
                    int l = i + 1, r = j - 1;
                    while (l <= r && S[l] != S[i]) l++;
                    while (l <= r && S[r] != S[j]) r--;
                    if (l > r) dp[i][j] += 2;
                    else if (l == r) dp[i][j] += 1;
                    else dp[i][j] -= dp[l + 1][r - 1];
                } else dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + num_mod : dp[i][j] % num_mod;
            }
        }
        return dp[0][n - 1];
    }
};