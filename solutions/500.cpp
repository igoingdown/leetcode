class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1("qwertyuiop");
        string s2("asdfghjkl");
        string s3("zxcvbnm");
        vector<int> m(26);
        for (char c : s1) m[c - 'a'] = 1;
        for (char c : s2) m[c - 'a'] = 2;
        for (char c : s3) m[c - 'a'] = 3;
        vector<string> res;
        for (const string &w: words) {
            int i = 1;
            while (i < w.size() && m[tolower(w[i]) - 'a'] == m[tolower(w[i-1]) - 'a']) i++;
            if (i >= w.size()) res.push_back(w);
        }
        return res;
    }
};