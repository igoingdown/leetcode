class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string s = "1";
        while (--n) {
            int b = 0, e = 0, l = s.size();
            string res = "";
            while (b < l) {
                while (e < l && s[b] == s[e]) e++;
                res += to_string(e - b);
                res += s[b];
                b = e;
            }
            s = res;
        }
        return s;
    }
};