class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res(0);
        int s = A.size();
        if (s < 1) return res;
        res.resize(s, 0);
        map<int, vector<int>::iterator> m;
        for (int i = 0; i < A.size(); i++) {
            if (m.find(A[i]) == m.end()) m[A[i]] = B.begin();
            auto iter = find(m[A[i]], B.end(), A[i]);
            res[i] = iter - B.begin();
            m[A[i]] = iter + 1;
        }
        return res;
    }
};