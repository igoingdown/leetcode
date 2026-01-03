class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            auto iter = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if (iter != matrix[i].end() && *iter == target) return true;
        }
        return false;
    }
};