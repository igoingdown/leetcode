class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        // 推理得出序列长度的范围
        for (int i = 1; i <= sqrt(N * 2); i++) {
            long long low = 1, high = N, mid;
            // 二分查找
            while (low < high) {
                mid = low + ((high - low ) >> 1);
                double mid_t = ((double)mid * 2 + i - 1) * i / 2;
                if (mid_t < N) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            if (((double)low * 2 + i - 1) * i / 2 == N) res++;
        }
        return res;
    }
};