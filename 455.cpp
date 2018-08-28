class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size();
        if (m == 0 || n == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (g[i] <= s[j]) i++;
            j++;
        }
        return i;
    }
};