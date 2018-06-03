class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        vector<int> dp1(n), dp2(n);
        for (int i = 0; i < n; i++) {
            if (i > 0 && A[i] > A[i - 1]) dp1[i] = dp1[i - 1] + 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && A[i] > A[i + 1]) dp2[i] = dp2[i + 1] + 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dp1[i] == 0 || dp2[i] == 0 ? 0 : 1 + dp1[i] + dp2[i]);
        }
        return res >= 3 ? res : 0;
    }
};