class Solution {
public:
    string reorganizeString(string S) {
        vector<int> v(26, 0);
        for (char c : S) v[c - 'a']++;
        string res = "";
        dfs(res, v, S);
        return res;
    }
    void dfs(string& res, vector<int>& v, const string& S) {
        if (res.size() == S.size()) return;
        for (int i = 0; i < 26; i++) {
            if (v[i] > 0) {
                if (res.size() == 0 || res.back() != 'a' + i) {
                    res += ('a' + i);
                    v[i]--;
                    dfs(res, v, S);
                    if (res.size() == S.size()) return;
                    v[i]++;
                    res.pop_back();
                }
            }
        }
    }
};
