class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        if ((num & (-num)) != num) return false;
        return (num & (-num)) & 0x55555555;
    }
};