class Solution {
private:
    void get_next(vector<int>& v, const string& str) {
        int i = 0, j = -1;
        v[i] = j;
        while (i < str.size() - 1) {
            if (j == -1 || str[i] == str[j]) v[++i] = ++j;
            else j = v[j];
        }
    }
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n == 0) return 0;
        if (m == 0) return -1;
        vector<int> next(n, 0);
        get_next(next, needle);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++; j++;
            } else j = next[j];
        }
        return j == needle.size() ? i - j : -1;
    }
};