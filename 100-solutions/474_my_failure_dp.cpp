class Solution {
public:
    static bool myComp(string s1, string s2) {
        return s1.size() < s2.size();
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector< vector< bitset<600> > > dp(m + 1, vector< bitset<600> > (n + 1, bitset<600>(0)));
        sort(strs.begin(), strs.end(), myComp);
        int sum1 = 0, sum0 = 0;
        for (int i = 0; i < strs.size(); i++) {
            if (count(strs[i].begin(), strs[i].end(), '1') == strs[i].size()) {
                if (sum1 + strs[i].size() <= n) {
                    sum1 += strs[i].size();
                    dp[0][sum1] = dp[0][sum1 - strs[i].size()];
                    dp[0][sum1].set(i);
                }
            } else if (count(strs[i].begin(), strs[i].end(), '1') == 0) {
                if (sum0 + strs[i].size() <= n) {
                    sum0 += strs[i].size();
                    dp[sum0][0] = dp[sum0 - strs[i].size()][0];
                    dp[sum0][0].set(i);
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (dp[i][0].count() == 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int j = 1; j < n; j++) {
            if (dp[0][j].count() == 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = 0; k < strs.size(); k++) {
                    int zeros = count(strs[i].begin(), strs[i].end(), '0');
                    int ones = strs[i].size() - zeros;
                    if (i - zeros >= 0 && j - ones >= 0 && !dp[i - zeros][j - ones].test(k) && dp[i - zeros][j - ones].count() + 1 > dp[i][j].count()) {
                        dp[i][j] = dp[i - zeros][j - ones];
                        dp[i][j].set(k);
                    }
                }
                if (!(dp[i][j].count() > dp[i - 1][j].count() && dp[i][j].count() > dp[i][j].count())) {
                    dp[i][j - 1].count() > dp[i - 1][j].count() ? dp[i][j] = dp[i][j - 1] : dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n].count();
    }
};