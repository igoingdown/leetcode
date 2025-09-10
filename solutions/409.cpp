class Solution {
public:
    int longestPalindrome(string s) {
        int a[100] = {};
        int res = 0;
        for (auto c: s) {
            if (a[c - 'A']) {
                res += 2;
                a[c - 'A']--;
            } else {
                a[c - 'A']++;
            }
        }
        for (int i = 0; i < 52; i++) {
            if (a[i]) {
                res++;
                break;
            }
        }
        return res;
    }
};