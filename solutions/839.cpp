class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size(), groups = n;
        if (n == 0) return groups;
        vector<int> leads(n);
        for (int i = 0; i < n; i++) leads[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isSimilar(A[i], A[j])) {
                    int x = find(i, leads), y = find(j, leads);
                    if (x != y) {
                        groups--;
                        leads[x] = y;
                    }
                }
            }
        }
        return groups;
    }
    
    bool isSimilar(string &a, string &b) {
        int n = a.size(), x = -1, y = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (y >= 0) return false;
                if (x < 0) x = i;
                else y = i;
            }
        }
        return true;
    }
    
    int find(int i, vector<int> &parents) {
        return i == parents[i] ? i : find(parents[i], parents);
    }
};