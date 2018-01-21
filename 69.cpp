class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int low = 1, high = x, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (x / mid > mid) low = mid + 1;
            else if(x / mid < mid) high = mid;
            else return mid;
        }
        return low * low == x ? low : low - 1;
    }
};