class Solution {
public:
    int bestRotation(vector<int>& A) {
        int max_points = 0, min_k = 0;
        for (int k = 0; k < A.size(); k++) {
            int points = 0;
            for (int i = 0; i < A.size(); i++) points += A[(i + k) % A.size()] <= i ? 1 : 0;
            if (points > max_points) {
                max_points = points; min_k = k;
            }
        }
        return min_k;
    }
};