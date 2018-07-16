class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long long gas = startFuel;
        int n = stations.size();
        for (int i = 0; i < n; i++) gas += stations[i][1];
        if (gas < target) return -1;
        sort(stations.begin(), stations.end());
        priority_queue<int> q;
        long long i = 0, d = startFuel, res = 0;
        while (d < target) {
            while (i < n && stations[i][0] <= d) q.push(stations[i++][1]);
            if (q.empty()) return -1;
            d += q.top();
            q.pop();
            res++;
        }
        return res;
    }
};