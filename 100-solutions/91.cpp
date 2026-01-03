class Solution {
public:
    int numDecodings(string s) {
        if (s.size() < 1) return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (dp[i - 1] == 0) return 0;
            dp[i] += s[i - 1] == '0' ? 0 : dp[i - 1];
            if (i < 2) continue;
            int sum = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            dp[i] +=  (sum <= 26 && sum >= 10) ? dp[i - 2] : 0;
        }
        return dp[s.size()];
    }
};