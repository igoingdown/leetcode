class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if (N < 1) return 0;
        vector<int> d(N, INT_MAX);
        vector<vector<int>> m(N, vector<int>(N, -1));
        for (auto v : times) m[v[0] - 1][v[1] - 1] = v[2];
        queue<int> q, next;
        q.push(K - 1);
        d[K - 1] = 0;
        while (!q.empty()) {
            set<int> s;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v = 0; v < N; v++) {
                    if (m[u][v] >= 0 && d[u] + m[u][v] < d[v]) {
                        if (s.find(v) == s.end()) {
                            s.insert(v);
                            next.push(v);
                        }
                        d[v] = d[u] + m[u][v];
                    }
                }
            }
            swap(q, next);
        }
        int res = 0;
        for (auto n : d) res = max(n, res);
        return res == INT_MAX ? -1 : res;
    }
};