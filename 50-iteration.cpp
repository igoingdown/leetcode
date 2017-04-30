class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        long b = n;
        if (b < 0) {
            b = -b;
            x = 1 / x;
        }
        double res = 1;
        while (b) {
            if (b & 1) {
                res *= x;
            }
            x *= x;
            b >>= 1;
        }
        return res;
    }
};
