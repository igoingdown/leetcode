class Solution {
public:
    int reverse(int x) {
        int sign = 1, res = 0;
        if (x == INT_MIN) return res;
        if (x < 0) {
            sign = -1;
            x *= -1;
        }
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
            if ((res > INT_MAX / 10 && x) || (res == INT_MAX / 10) && ((x > INT_MAX % 10 && sign > 0) || (x > INT_MAX % 10 + 1 && sign < 0))) return 0;
        }
        return res * sign;
    }


    int reverse2(int x) {
        long long a = x;
        int sign = 1;
        if (a < 0) {
            a = -a;
            sign = -1;
        }
        long long res = 0;
        while (a) {
            res = res * 10 + a % 10;
            a /= 10;
        }
        res *= sign;
        return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};

