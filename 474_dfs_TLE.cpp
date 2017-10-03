class Solution {
private:
    int dfs(bitset<600>& s, vector<string>& strs, int m, int n, int b) {
        if (m < 0 || n < 0) {
            return s.count() - 1;
        } else if ((m == 0 && n == 0) || (b >= strs.size())) {
            return s.count();
        }
        int res = 0;
        for (int i = b; i < strs.size(); i++) {
            if (!(s.test(i))) {
                int zeros = count(strs[i].begin(), strs[i].end(), '0');
                res = max(res, dfs(s.set(i), strs, m - zeros, n - (strs[i].size() - zeros), i + 1));
                s.reset(i);
            }
        }
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        bitset<600> s(0);
        return dfs(s, strs, m, n, 0);
    }
};