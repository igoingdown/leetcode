class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int dp[1 << 12][12];
        memset(dp, 100, sizeof dp);
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 0;
            q.push({1 << i, i});
        }
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int s = p.first, v = p.second;
            for (int e : graph[v]) {
                int t = s | 1 << e;
                if (dp[t][e] > dp[s][v] + 1) {
                    dp[t][e] = dp[s][v] + 1;
                    q.push({t, e});
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) res = min(res, dp[(1 << n) - 1][i]);
        return res;
    }
};