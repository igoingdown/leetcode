class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (mid * mid < num) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return (low * low == num);
    }
};
