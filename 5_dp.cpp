class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, end = 0;
        if (n < 2) return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = s[i] == s[j] && (i + 2 > j || dp[i + 1][j - 1]);
                if (dp[i][j]) {start = i; end = j;}
            }
        }
        return s.substr(start, end - start + 1);
    }
};