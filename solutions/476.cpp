class Solution {
public:
    int findComplement(int num) {
        int res = 0, i = 31;
        while (i >= 0 && (num >> i & 1) == 0) {
            res |= 1 << i;
            i--;
        }
        while (i >= 0) {
            res |= (num >> i & 1) << i;
            i--;
        }
        return ~res;
    }
};