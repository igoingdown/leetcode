class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int b = 0, e = 0;
        while (b < n && e < n) {
            while (b < n && s[b] == ' ') b++;
            e = b;
            while (e < n && s[e] != ' ') e++;
            reverse(s.begin() + b, s.begin() + e);
            b = e;
        }
        return s;
    }
};