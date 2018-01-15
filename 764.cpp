class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> m(N, vector<int> (N, 1));
        for (auto v: mines) m[v[0]][v[1]] = 0;
        vector<vector<int>> l(N, vector<int>(N, 0)), r = l, d = l, u = l;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (m[i][j]) {
                    l[i][j] = j == 0 ? 1 : 1 + l[i][j - 1];
                    u[i][j] = i == 0 ? 1 : 1 + u[i - 1][j];
                }
            }
        }
        int ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (m[i][j]) {
                    r[i][j] = j == N - 1 ? 1 : 1 + r[i][j + 1];
                    d[i][j] = i == N - 1 ? 1 : 1 + d[i + 1][j];
                    ans = max(ans, min(l[i][j], min(r[i][j], min(u[i][j], d[i][j]))));
                }
            }
        }
        return ans;
    }
};