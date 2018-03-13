class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1), next(res);
        if (rowIndex < 2) return res;
        for (int r = 2; r <= rowIndex; r++) {
            for (int c = 1; c < r; c++) next[c] = res[c] + res[c - 1];
            swap(res, next);
        }
        return res;
    }
};