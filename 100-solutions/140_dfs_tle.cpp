class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string path = "";
        vector<string> res;
        unordered_set<string> dict;
        int max_len = 0;
        for (string word : wordDict) {
            dict.insert(word); max_len = max(max_len, (int)word.size());
        }
        dfs(s, dict, 0, path, max_len, res);
        return res;
    }
    
    void dfs(string &s, const unordered_set<string> &dict, int start, string &path, const int &max_len, vector<string> &res) {
        if (start >= s.size()) {
            if (path.size() > 0 && path.back() == ' ') res.push_back(path.substr(0, path.size() - 1));
            return;
        }
        for (int i = 0; i < max_len; i++) {
            if (start + i >= s.size()) break;
            string tmp = s.substr(start, i + 1);
            if (dict.find(tmp) != dict.end()) {
                path += (tmp + " ");
                dfs(s, dict, start + i + 1, path, max_len, res);
                path.resize(path.size() - i - 2);
            }
        }
    }
};