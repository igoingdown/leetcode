class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        int d = num.size() - k;
        for (char c : num) {
            while (s.size() && s.back() > c && k > 0) {
                s.pop_back();
                k--;
            }
            s += c;
        }
        int i = 0;
        while (i < d && s[i] == '0') {
            i++;
        }
        return i == (d) ? "0" : s.substr(i, d - i);
    }
};