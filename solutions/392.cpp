class Solution {
public:
    bool isSubsequence_1(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) {
            return false;
        }
        int i = 0, j = 0;
        for (; i < m && j < n; j++) {
            if (s[i] == t[j]) {
                i++;
            }
        }
        return i == m;
    }

};