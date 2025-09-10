class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        dfs(res, path, n, n);
        return res;
    }
    void dfs(vector<string>& res, string path, int l, int r) {
        if (l <= 0 && r <= 0) res.push_back(path);
        if (l > 0) dfs(res, path + "(", l - 1, r);
        if (l < r) dfs(res, path + ")", l, r - 1);
    }
};