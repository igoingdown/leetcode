class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        while ((n -= i) >= 0) {
            i++;
        }
        return i - 1;
    }
};
