class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        if ((num & (-num)) != num) return false;
        int i = 0;
        while (i < 32) {
            if (num >> i & 1) break;
            i++;
        }
        return i % 2 == 0;
    }
};