class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<vector<int>> indice(words.size(), vector<int>(0));
        for (int i = 0; i < words.size(); i++) findMatchIndice(s, words[i], indice[i]);
        for (auto v : indice) {
            for (auto i : v) cout << i << " ";
            cout << endl;
        }
        vector<int> res; set<string> visited;
        dfs(words, 0, -1, indice, visited, res);
        return res;
    }
    
    void dfs(vector<string> &words, int start, int end, vector<vector<int>> &indice, set<string> &visited, vector<int> &res) {
        if (visited.size() == words.size()) {
            res.push_back(start); return;
        }
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            if (visited.find(word) == visited.end()) {
                if (start > end) {
                    visited.insert(word);
                    for (int b : indice[i]) dfs(words, b, b + word.size() - 1, indice, visited, res);
                    visited.erase(word);
                } else {
                    for (int b : indice[i]) {
                        if (start - word.size() == b || end + word.size() == b) {
                            visited.insert(word);
                            if (end + word.size() == b) dfs(words, start, end + word.size(), indice, visited, res);
                            else dfs(words, start - word.size(), end, indice, visited, res);
                            visited.erase(word);
                        }
                    }
                }
            }
        }
    }
    
    void getNext(string &s, vector<int>& next) {
        int i = 0, j = -1;
        while (i < s.size()) {
            if (j == -1 || (s[i] == s[j])) next[++i] = ++j;
            else j = -1;
        }
    }
    
    void findMatchIndice(string &s, string &p, vector<int> &res) {
        vector<int> next(p.size(), -1);
        getNext(p, next);
        int i = 0, j = 0;
        while (i < s.size()) {
            if (j == p.size()) {
                res.push_back(i - j); j = 0;
            }
            if (j == -1 || s[i] == p[j]) {
                ++i, ++j;
            } else {
                j = next[j];
            }
        }
    }
};
