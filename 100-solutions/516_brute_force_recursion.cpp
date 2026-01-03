class Solution {
private:
    int helper(int l, int r, string s) {
        if (l == r) {
            return 1;
        } else if (l > r) {
            return 0;
        }
        return s[l] == s[r] ? 2 + helper(l + 1, r - 1, s) : max(helper(l + 1, r, s), helper(l, r - 1, s));
    }
public:
    int longestPalindromeSubseq(string s) {
        return helper(0, s.size() - 1, s);
    }
};