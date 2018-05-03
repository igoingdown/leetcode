class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        if (n == 0) return 0;
        if (n == 1) return words[0].size() + 1;
        int res = 0;
        for (string &word : words) {
            res += word.size() + 1;
            reverse(word.begin(), word.end());
        }
        sort(words.begin(), words.end());
        for (int i = 0; i + 1 < n; i++) {
            if (isSubstring(words[i], words[i + 1])) res -= words[i].size() + 1;
        }
        return res;
    }

    bool isSubstring(const string &s1, const string &s2) {
        if (s1.size() > s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
};
