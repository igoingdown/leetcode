class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n;
        if (m == 0) return false;
        n = matrix[0].size();
        if (n == 0) return false;
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            else if (cur > target) col--;
            else row++;
        }
        return false;
    }
};