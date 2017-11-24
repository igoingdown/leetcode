class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> m1;
        map<string, char> m2;
        stringstream ss(str);
        string tmp;
        vector<string> strs;
        while (getline(ss, tmp, ' ')) {
            strs.push_back(tmp);
        }
        int m = strs.size(), n = pattern.size();
        if (m != n) return false;
        for (int i = 0; i < n; i++) {
            if (m1.find(pattern[i]) == m1.end()) {
                if (m2.find(strs[i]) != m2.end()) return false;
                else {
                    m1[pattern[i]] = strs[i];
                    m2[strs[i]] = pattern[i];
                }
            } else {
                if (m2.find(strs[i]) == m2.end()) return false;
                else if (m2[strs[i]] != pattern[i] || m1[pattern[i]] != strs[i]) return false;
            }
        }
        return true;
    }
};