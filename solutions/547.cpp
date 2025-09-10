
class Solution {
private:
    void dfs(vector<vector<int>>& M, vector<int>& m, int start, int id) {
        int n = M.size();
        for (int i = 1; i < n + 1; i++) {
            if (M[start - 1][i - 1]) {
                if (!m[i]) {
                    m[i] = id;
                    dfs(M, m, i, id);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n < 1) return 0;
        vector<int> m(n + 1, 0);
        for (int i = 1; i < n + 1; i++) dfs(M, m, i, i);
        set<int> s;
        for (int i = 1; i < n + 1; i++) s.insert(m[i]);
        return s.size();
    }
};