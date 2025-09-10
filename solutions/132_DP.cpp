class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n < 2) return 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> minCut(n + 1);
        for (int i = 0; i <= n; i++) minCut[i] = i - 1;
        for (int i = 0; i < n; i++) dp[i][i] = true;
        for (int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (j + 2 > i || dp[j + 1][i - 1])) dp[j][i] = true;
                if (dp[j][i]) minCut[i + 1] = min(1 + minCut[j], minCut[i + 1]);
            }
        }
        return minCut[n];
    }
};