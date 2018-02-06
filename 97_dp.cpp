class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3) return false;
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
        for (int i = 0; i <= l1; i++) {
            if (s1.substr(0, i) == s3.substr(0, i)) dp[i][0] = true;
        }
        for (int j = 1; j <= l2; j++) {
            if (s2.substr(0, j) == s3.substr(0, j)) dp[0][j] = true;
        }
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) dp[i][j] = true;
                if (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) dp[i][j] = true;
            }
        }
        return dp[l1][l2];
    }
};