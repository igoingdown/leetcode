class Solution {
public:
    int strStr(string haystack, string needle) {
        int hs = haystack.size(), ns = needle.size();
        if (ns == 0) return 0;
        if (hs == 0) return -1;
        vector<int> next(ns, -1);
        getNext(needle, next);
        int i = 0, j = 0;
        while (i < hs && j < ns) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        return j == ns ? i - j : -1;
    }
    
    void getNext(string &s, vector<int> &next) {
        int i = 0, j = -1;
        while (i + 1 < s.size()) {
            if (j == - 1 || s[i] == s[j]) next[++i] = ++j;
            else j = next[j];
        }
    }
};
