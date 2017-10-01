class Solution {
private:
    int helper(int l, int r, string s, vector< vector<int> >& m) {
        if (l == r) {
            return 1;
        } else if (l > r) {
            return 0;
        }
        if (m[l][r]) return m[l][r];
        return m[l][r] = s[l] == s[r] ? 2 + helper(l + 1, r - 1, s, m) : max(helper(l + 1, r, s, m), helper(l, r - 1, s, m));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector< vector<int> > m(n, vector<int> (n, 0));
        return helper(0, s.size() - 1, s, m);
    }
};