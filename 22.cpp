class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        dfs(res, path, n, n);
        return res;
    }
    void dfs(vector<string>& res, string path, int l, int r) {
        if (!l && !r) {
            res.push_back(path);
            return;
        }
        if (l > 0) dfs(res, path + "(", l - 1, r);
        if (l < r) dfs(res, path + ")", l, r - 1);
    }
};