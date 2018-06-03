class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        string h;
        for (int i = n - 1; i >= 0; i--) {
            if ((i & 1) == 1) {
                int l = i / 2, r = l + 1;
                while (l >= 0 && s[l] == s[r]) {
                    l--; r++;
                }
                if (l < 0) {
                    h = s.substr(r);
                    break;
                }
            } else {
                int m = i / 2, j = 0;
                while (j <= m && s[m - j] == s[m + j]) j++;
                if (j > m) {
                    h = s.substr(m + j);
                    break;
                }
            }
        }
        reverse(h.begin(), h.end());
        return h + s;
    }
};