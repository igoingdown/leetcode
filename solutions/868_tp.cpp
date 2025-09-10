class Solution {
public:
    int binaryGap(int N) {
        bitset<32> bs(N);
        int b = 0, e = -1, res = 0;
        while (b < 32 && e < 32) {
            while (b < 32 && !bs.test(b)) b++;
            if (e >= 0 && b < 32) res = max(b - e, res);
            e = b;
            b++;
        }
        return res;
    }
};