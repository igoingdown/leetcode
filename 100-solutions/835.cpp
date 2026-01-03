class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        if (n == 0) return 0;
        int res = 0;
        for (int ai = 0; ai < n; ai++) {
            for (int aj = 0; aj < n; aj++) {
                int a_count = 0, b_count = 0, c_count = 0, d_count = 0;
                for (int bi = 0; bi < n; bi++) {
                    for (int bj = 0; bj < n; bj++) {
                        if (ai + bi < n && aj + bj < n && A[ai+bi][aj+bj] == B[bi][bj] && B[bi][bj] == 1) a_count++;
                        if (ai + bi < n && aj + bj < n && B[ai+bi][aj+bj] == A[bi][bj] && A[bi][bj] == 1) b_count++;
                        if (ai - (n - 1 - bi) >= 0 && aj + bj < n && A[ai-(n-1-bi)][aj+bj] == B[bi][bj] && B[bi][bj] == 1) c_count++;
                        if (ai + bi < n && aj - (n - 1 - bj) >= 0 && A[ai+bi][aj-(n-1-bj)] == B[bi][bj] && B[bi][bj] == 1) d_count++;
                    }
                }
                res = max(res, a_count); res = max(res, b_count); res = max(res, c_count); res = max(res, d_count);
            }
        }
        return res;
    }
};