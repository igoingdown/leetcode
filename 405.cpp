class Solution {
public:
    string toHex(int num) {
        string s;
        for (int i = 0 ; i < 8 && num; i++) {
            int n = 0;
            for (int j = 0; j < 4; j++) {
                n += (num & 1) << j;
                num = num >> 1;
            }
            s += n > 9 ? ('a' + n - 10) : ('0' + n);
        }
        reverse(s.begin(), s.end());
        return s.size() == 0 ? "0" : s;
    }
};