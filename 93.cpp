class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path = "";
        dfs(s, res, 0, path, 0);
        return res;
    }
    void dfs(string& s, vector<string>& res, int c, string p, int start) {
        if (start > s.size() || c > 4) return;
        if (c == 4 && start == s.size()) {
            res.push_back(p);
            return;
        }
        for (int i = 1; i < 4 && i + start <= s.size(); i++) {
            string a = s.substr(start, i);
            if ((i > 1 && a[0] == '0') || (stoi(a) > 255)) break;
            dfs(s, res, c + 1, p + a + (c == 3 ? "" : "."), start + i);
        }
    }
};