class Solution {
public:
    string minWindow(string s, string t) {
        int text[256] = {0}, pattern[256] = {0};
        for (char c : t) pattern[c]++;
        int start = 0, end = 0, min_start = 0, min_len = s.size() + 1, count = t.size(), n = s.size();
        bool included = false;
        text[s[0]]++;
        if (pattern[s[0]] > 0) count--;
        while (1) {
            if (count == 0) {
                included = true;
                while (text[s[start]] > pattern[s[start]]) text[s[start++]]--;
                if (min_len > end - start + 1) {
                    min_start = start;
                    min_len = end - start + 1;
                }
            }
            if (end < n - 1) {
                text[s[++end]]++;
                if (pattern[s[end]] >= text[s[end]]) count--;
            } else break;
        }
        return included ? s.substr(min_start, min_len) : "";
    }
};