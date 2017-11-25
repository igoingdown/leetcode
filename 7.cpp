class Solution {
public:
    int reverse(int x) {
        int res = 0;
        if (x == INT_MIN) return res;
        int tmp = abs(x);
        while (tmp) { 
            res = (res * 10) + (tmp % 10);
            tmp /= 10;
            if ((res > INT_MAX / 10 && tmp) || (res == INT_MAX / 10 && tmp > 7 && x > 0) || (res == INT_MAX / 10 && tmp > 8 && res < 0)) return 0; 
        }
        return x < 0 ? -res : res;
    }
};