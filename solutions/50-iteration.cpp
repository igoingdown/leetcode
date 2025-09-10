class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x < 1e-6 && x > -1e-6) return 0;
        long long b = n;
        if (n < 0) {
            b = -b;
            x = 1 / x;
        }
        double res = 1;
        while (b) {
            if (b & 1) res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};