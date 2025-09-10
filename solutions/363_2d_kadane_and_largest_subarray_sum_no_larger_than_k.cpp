class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col, res = INT_MIN, cum = 0;
        if (row == 0) return 0;
        col = matrix[0].size();
        if (col == 0) return 0;
        set<int> cums;
        for (int left = 0; left < col; left++) {
            vector<int> rowSum(row, 0);
            for (int right = left + 1; right <= col; right++) {
                for (int i = 0; i < row; i++) rowSum[i] += matrix[i][right - 1];
                
                // largest subarray sum with upper bound k in an array
                cums.clear();
                cums.insert(0);
                cum = 0;
                for (int num : rowSum) {
                    cum += num;
                    auto iter = lower_bound(cums.begin(), cums.end(), cum - k);
                    if (iter != cums.end()) res = max(res, cum - *iter);
                    cums.insert(cum);
                }
            }
        }
        return res;
    }
};