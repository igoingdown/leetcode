class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else {
            long b = n;
            if (n < 0) {
                b = -b;
                x = 1 / x;
            }
            return b % 2 == 0 ? myPow(x * x, b / 2) : x * myPow(x * x, b / 2);
        }
    }
};
