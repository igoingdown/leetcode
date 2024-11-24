
class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        unsigned int n = num;
        string hexMap = "0123456789abcdef";
        string res;
        while (n) {
            res += hexMap[n & 0xf];
            n = n >> 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
