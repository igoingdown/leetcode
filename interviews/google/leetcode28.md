```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int ns = needle.size(), hs = haystack.size(), i = 0, j = 0;
        if (ns == 0) return 0;
        vector<int> next(ns);
        getNext(needle, next);
        while (i < hs && j < ns) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++; j++;
            } else j = next[j];
        }
        return j == ns ? i - j : -1;
    }
    
    void getNext(string &s, vector<int> &next) {
        int i = 0, j = -1, ss = s.size();
        next[i] = j;
        while (i < ss - 1) {
            if (j == -1 || s[i] == s[j]) next[++i] = ++j;
            else j = next[j];
        }
    }
};
```