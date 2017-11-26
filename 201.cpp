class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                tmp = (tmp << 1 | 1);
            }
            for (int j = i + 1; j < 32; j++) {
                tmp |= ((n >> j & 1) << j);
            }
            if (m > tmp) {
                res |= (1 << i);
            }
        }
        return res;
    }
};