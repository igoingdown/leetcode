class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size(), group = n;
        vector<int> leads(n);
        for (int i = 0; i < n; i++) leads[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j]) {
                    int lead1 = find(i, leads);
                    int lead2 = find(j, leads);
                    if (lead1 != lead2) {
                        leads[lead1] = lead2; 
                        group--;
                    }
                }
            }
        }
        return group;
    }
    int find(int i, vector<int>& parents) {
        while (i != parents[i]) {
            parents[i] = parents[parents[i]];
            i = parents[i];
        }
        return i;
    }
};