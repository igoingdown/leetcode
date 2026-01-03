class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1, res = 0, multi;
        long long d = labs(dividend), s = labs(divisor), tmp;
        while (d >= s) {
            tmp = s;
            multi = 1;
            while (d >= (tmp << 1)) {
                tmp <<= 1;
                multi <<= 1;
            }
            res += multi;
            d -= tmp;
        }
        return res * sign;
    }
};