class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if (N < 1 ) return 0;
        map<int, map<int, int>> g;
        for (auto t : times) g[t[0]][t[1]] = t[2];
        vector<bool> visit(N + 1, false);
        vector<int> dis(N + 1, INT_MAX);
        int pre = K;
        dis[K] = 0;
        while (pre > 0) {
            visit[pre] = true;
            for (auto p : g[pre]) dis[p.first] = min(dis[p.first], dis[pre] + p.second);
            int min_node = -1;
            for (int i = 1; i <= N; i++) {
                if (!visit[i]) {
                    if (min_node > 0) min_node = dis[min_node] > dis[i] ? i : min_node;
                    else min_node = i;
                }
            }
            pre = min_node;
        }
        int res = INT_MIN;
        for (int i = 1; i <= N; i++) res = max(res, dis[i]);
        return res == INT_MAX ? -1 : res;
    }
};