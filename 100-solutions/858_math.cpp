class Solution {
public:
    int mirrorReflection(int p, int q) {
        for (int i = 1; ; i++) {
            int y = i * q % (2 * p);
            if (y == 0) return 0;
            else if (y == p) {
                return i % 2 == 1 ? 1 : 2;
            }
        }
    }
};