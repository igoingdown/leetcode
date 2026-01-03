class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        sort(A.begin(), A.end(), greater<int>());
        vector<pair<int, int>> bb;
        for (int i = 0; i < n; i++) bb.push_back({B[i], i});
        sort(bb.begin(), bb.end(), greater<pair<int, int>>());
        vector<int> res(n, -1);
        int i = 0;
        for (int j = 0; i < n; i++) {
            while (j < n && bb[j].first >= A[i]) j++;
            if (j >= n) break;
            res[bb[j].second] = A[i];
            j++;
        }
        for (int k = i, j = 0; i < n; i++) {
            while (j < n && res[j] >= 0) j++;
            if (j >= n) break;
            res[j] = A[i];
            j++;
        }
        return res;
    }
};