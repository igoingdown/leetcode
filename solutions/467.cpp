class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int n = p.size(), curLen = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25)) {
                curLen ++;
            } else {
                curLen = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], curLen);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};