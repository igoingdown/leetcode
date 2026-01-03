class Solution {
public:
    int longestValidParentheses(string s) {
        int ss = s.size(), res = 0;
        vector<vector<bool>> dp(ss, vector<bool>(ss, false));
        for (int len = 2; len <= ss; len++) {
            for (int i = 0; i + len <= ss; i++) {
                int j = i + len - 1;
                if (len == 2) dp[i][j] = s[i] == '(' && s[j] == ')';
                else if (s[i] == '(' && s[j] == ')' && dp[i + 1][j - 1]) dp[i][j] = true;
                else {
                    for (int k = i + 1; k < j - 1; k++) {
                        if (dp[i][k] && dp[k + 1][j]) {
                            dp[i][j] = true; break;
                        }
                    }
                }
                if (dp[i][j]) res = max(res, len);
            }
        }
        return res;
    }
};