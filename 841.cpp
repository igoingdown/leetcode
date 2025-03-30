class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n);
        queue<int> cur, next;
        visited[0] = true;
        cur.push(0);
        while (!cur.empty()) {
            while (!cur.empty()) {
                int node = cur.front(); cur.pop();
                for (auto key: rooms[node]) {
                    if (!visited[key]) {
                        next.push(key);
                    }
                    visited[key] = true;
                }
            }
            swap(cur, next);
        }
        for (auto b : visited) {
            if (!b) {
                return false;
            }
        }
        return true;
    }
};
