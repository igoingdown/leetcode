class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i, m, n;
        for (i = 0; i < 32; i++) {
            m = left >> i;
            n = right >> i;
            if ( m == n) {
                break;
            }
        }
        return m << i;
    }
};
