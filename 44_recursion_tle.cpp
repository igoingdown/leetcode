class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
    bool isMatch(const string& s, int spos, const string& p, int ppos) {
        if (ppos == p.size() && s.size() == spos) return true;
        if (ppos == p.size() || spos > s.size()) return false;
        if (p[ppos] == '?') {
            if (isMatch(s, spos + 1, p, ppos + 1)) return true;
        } else if (p[ppos] == '*') {
            for (int i = spos; i <= s.size(); i++) if (isMatch(s, i, p, ppos + 1)) return true;
        } else {
            if (p[ppos] == s[spos] && isMatch(s, spos + 1, p, ppos + 1)) return true;
        }
        return false;
    }
};