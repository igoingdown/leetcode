class Solution {
public:
    bool isMatch(string s, string p) {
        int ss = s.size(), ps = p.size();
        if (ps == 0) return ss == 0;
        vector<vector<bool>> dp(ss + 1, vector<bool>(ps + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < ps; i++) {
            if (p[i] == '*') {
                for (int j = 0; j <= ss; j++) {
                    if (dp[j][i]) {
                        dp[j][i + 1] = true;
                        for (int k = j; k < ss; k++) dp[k + 1][i + 1] = true;
                    }
                }
            }
            if (p[i] == '?') {
                for (int j = 0; j < ss; j++) {
                    if (dp[j][i]) dp[j + 1][i + 1] = true;
                }
                
            } else {
                for (int j = 0; j < ss; j++) {
                    if (s[j] == p[i] && dp[j][i]) dp[j + 1][i + 1] = true;
                }
            }
        }
        return dp[ss][ps];
    }
};