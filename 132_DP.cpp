class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n, 0);
        vector<vector<bool>> pal(n, vector<bool> (n, false));
        for (int i = 0; i < n; i++) {
            int m = i;
            // n个字母的string最多需要分割n-1次。
            for (int j = 0; j <= i; j++) {
                // 内层循环计算s[j, i]子串的最小分割m，用于更新cut[i]。
                if (s[i] == s[j] && (j + 2 > i || pal[j + 1][i - 1])) {
                    m = j == 0 ? 0 : min(m, cut[j - 1] + 1);
                    // min(m, cut[j - 1] + 1)的含义是j之前的字母到i不可能组成回文字符串，
                    // 因此s[0,j-1]的最小分割+1(s[j, 1]为回文字符串)是解，而且遍历过程中可以找到最优解。
                    pal[j][i] = true;
                }
            }
            cut[i] = m;
        }
        return cut[n - 1];
    }
};