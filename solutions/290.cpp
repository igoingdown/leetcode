class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        map<char, string> p_to_s;
        map<string, char> s_to_p;
        string word;
        int pos = 0;
        while (ss >> word) {
            if (pos >= pattern.size()) {
                return false;
            }
            if (p_to_s.find(pattern[pos]) == p_to_s.end() && s_to_p.find(word) == s_to_p.end()) {
                p_to_s[pattern[pos]] = word;
                s_to_p[word] = pattern[pos];
                ++pos;
                continue;
            }
            if (p_to_s.find(pattern[pos]) != p_to_s.end() && p_to_s[pattern[pos]] != word) {
                return false;
            }
            if (s_to_p.find(word) != s_to_p.end() && s_to_p[word] != pattern[pos]) {
                return false;
            }
            ++pos;
        }

        return pos == pattern.size();
    }
};