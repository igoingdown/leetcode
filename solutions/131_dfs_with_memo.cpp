class Solution {
private:
    map<pair<int, int>, int> m;
    void dfs(vector<vector<string>>& res, vector<string>& tmp, string& s, int start) {
        if (start == s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (!m[make_pair(start, i)]) {
                m[make_pair(start, i)] = is_palindrome(s, start, i);
            }
            if (m[make_pair(start, i)] > 0) {
                tmp.push_back(s.substr(start, i - start + 1));
                dfs(res, tmp, s, i + 1);
                tmp.pop_back();
            }
        }
    }
    
    int is_palindrome(const string& s, int b, int e) {
        if (b == e) {
            return 1;
        }
        while (b < e) {
            if (s[b++] != s[e--]) {
                return -1;
            }
        }
        return 1;
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(res, tmp, s, 0);
        return res;
    }
};