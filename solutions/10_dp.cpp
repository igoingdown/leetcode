class Solution {
public:
    bool isMatch(string s, string p) {
        int ss = s.size(), ps = p.size();
        vector<vector<bool>> dp(ss + 1, vector<bool>(ps + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= ps; j++) dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
        for (int i = 1; i <= ss; i++) {
            for (int j = 1; j <= ps; j++) {
                if (p[j - 1] == '*') dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
        return dp[ss][ps];
    }
};
