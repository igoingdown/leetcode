class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        for (int i = 1; i < s1.size(); i++) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) || 
                (isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) && isScramble(s1.substr(s1.size() - i), s2.substr(0, i)))) {
                return true;
            }
        }
        return false;
    }
};