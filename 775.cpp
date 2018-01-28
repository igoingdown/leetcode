class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = i - 1; j >= 0; j--) if (A[j] > A[i] && j != i - 1) return false;
        }
        return true;
    }
};