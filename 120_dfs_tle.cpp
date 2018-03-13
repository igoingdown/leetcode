class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if (m == 0) return 0;
        int res = INT_MAX;
        dfs(triangle, 1, 1, m, res, 0);
        return res;
    }
    void dfs(const vector<vector<int>> &triangle, int r, int c, const int &m, int &res, int sum) {
        if (r > m) {
            res = min(res, sum); return;
        }
        dfs(triangle, r + 1, c, m, res, sum + triangle[r - 1][c - 1]);
        dfs(triangle, r + 1, c + 1, m, res, sum + triangle[r - 1][c - 1]);
    }
};