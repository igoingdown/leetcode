class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n, mid;
        while (low < high) {
            mid = low + ((high - low) >> 1);
            if (!enough(m, n, mid, k)) low = mid + 1;
            else high = mid;
        }
        return low;
    }
private:
    bool enough(int m, int n, int t, int k) {
        int count = 0;
        for (int i = 1; i <= m; i++) count += min(t / i, n);
        return count >= k;
    }
};