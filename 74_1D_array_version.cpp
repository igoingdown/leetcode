class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        if (matrix[0].size() == 0) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = n * m - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid / n][mid % n] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return matrix[low / n][low % n] == target;
    }
};