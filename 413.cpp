class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        int m = 1, res = 0;
        while (m < A.size() - 1) {
            int b = m;
            while (A[m] * 2 == A[m - 1] + A[m + 1] && m < A.size() - 1) {
                m++;
            }
            if (m - b > 0) {
                res += (m - b) * (m - b + 1) / 2;
            } else {
                m++;
            }
        }
        return res;
    }
};
