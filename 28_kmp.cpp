class Solution {
public:
    int strStr(string haystack, string needle) {
        int hs = haystack.size(), ns = needle.size();
        if (ns == 0) return 0;
        if (hs == 0) return -1;
        vector<int> next(ns);
        int i = 0, j = -1;
        next[i] = j;
        while (i + 1 < ns) {
            if (j == -1 || needle[i] == needle[j]) next[++i] = ++j;
            else j = next[j];
        }
        i = 0; j = 0;
        while (i < hs && j < ns) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i; ++j;
            } else j = next[j];
        }
        return j == ns ? i - j : -1;
    }
};