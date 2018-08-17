class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> f(52);
        for (char c: s) {
            if (islower(c)) f[c - 'a']++;
            else if (isupper(c)) f[c - 'A' + 26]++;
        }
        int res = 0, flag = 0;
        for (int n : f) {
            if ((n & 1) == 0) res += n;
            else {
                res += n - 1;
                flag = 1;
            }
        }
        res += flag;
        return res;
    }
};