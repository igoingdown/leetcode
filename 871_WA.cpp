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
            long long next = d;
            while (i < n && stations[i][0] <= d) next = max(next, stations[i++][1] + d);
            if(next == d) return -1;
            d = next;
            res++;
        }
        return res;
    }
};