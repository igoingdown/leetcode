class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.size(), ps = p.size();
        return isMatch(s, 0, p, 0);
    }
    bool isMatch(string& s, int spos, string& p, int ppos) {
        if (ppos == p.size() && spos == s.size()) return true;
        if (ppos >= p.size() || spos > s.size()) return false;
        if (p[ppos] == '.') {
            if (ppos + 1 < p.size() && p[ppos + 1] == '*') {
                for (int i = spos; i <= s.size(); i++) {
                    if (isMatch(s, i, p, ppos + 2)) return true;
                }
            } else return isMatch(s, spos + 1, p, ppos + 1);
        } else if (p[ppos] != '*') {
            if (ppos + 1 < p.size() && p[ppos + 1] == '*') {
                if (isMatch(s, spos, p, ppos + 2)) return true;
                for (int i = spos; i < s.size() && s[i] == p[ppos]; i++){
                    if (isMatch(s, i + 1, p, ppos + 2)) return true;
                }
            } else return s[spos] == p[ppos] && isMatch(s, spos + 1, p, ppos + 1);
        }
        return false;
    }
};
