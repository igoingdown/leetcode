class Solution {
public:
    int minCut(string s) {
        int l = s.size();
        vector<int> cut(l, 0);
        vector<vector<bool>> pal(l, vector<bool> (l, false));
        for (int i = 0; i < l; i++) {
            int mini = i;
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (j + 2 > i || pal[j + 1][i - 1])) {
                    pal[j][i] = true;
                    mini = j == 0 ? 0 : min(mini, cut[j - 1] + 1);
                }
            }
            cut[i] = mini;
        }
        return cut[l - 1];
    }
};