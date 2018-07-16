class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long long gas = startFuel;
        int n = stations.size();
        vector<int> dis(n);
        for (int i = 0; i < n; i++) {
            dis[i] = stations[i][0];
            gas += stations[i][1];
        }
        if (gas < target) return -1;
        queue<pair<int, int>> q, next;
        q.push({0, startFuel});
        int res = 0;
        while (!q.empty()) {
            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                int start = p.first, end = p.second;
                if (p.second >= target) return res;
                auto iter = lower_bound(dis.begin(), dis.end(), start);
                for (int i = iter - dis.begin(); i < n && dis[i] <= end; i++) {
                    if (dis[i] == start) continue;
                    next.push({dis[i], end + stations[i][1]});
                }
            }
            swap(q, next);
            res++;
        }
        return -1;
    }
};