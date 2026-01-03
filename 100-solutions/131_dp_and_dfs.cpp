class Solution {
public:
    vector<vector<string>> partition(string s) {
        int l = s.size();
        vector<vector<bool>> dp(l, vector<bool>(l, false));
        for (int i = 0; i < l; i++) dp[i][i] = true;
        for (int j = 1; j < l; j++) {
            for (int i = 0; i < j; i++) dp[i][j] = s[i] == s[j] && (i + 1 > j - 1 || dp[i + 1][j - 1]);
        }
        vector<string> path;
        vector<vector<string>> res;
        dfs(s, path, dp, res, 0);
        return res;
    }
    void dfs(const string& s, vector<string>& path, vector<vector<bool>>& dp, vector<vector<string>>& res, int start) {
        if (start >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (dp[start][i]) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, path, dp, res, i + 1);
                path.pop_back();
            }
        }
    }
};