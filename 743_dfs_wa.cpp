class Solution {
public:
    vector<int> visited;
    vector<vector<int>> m;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if (N < 1) return 0;
        m.resize(N, vector<int>(N, -1));
        visited.resize(N, -1);
        for (auto v : times) m[v[0] - 1][v[1] - 1] = v[2];
        dfs(K - 1, N, 0);
        int res = 0;
        for (auto n : visited) {
            if (n < 0) return -1;
            res = max(res, n);
        }
        return res;
    }
    
    void dfs(int K, int N, int cost) {
        if (visited[K] >= 0) {
            visited[K] = min(cost, visited[K]);
            return;
        }
        visited[K] = cost;
        for (int i = 0; i < N; i++) {
            if (m[K][i] >= 0) dfs(i, N, cost + m[K][i]); 
        }
    }
};