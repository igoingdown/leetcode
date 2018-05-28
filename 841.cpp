class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> dp(n);
        dp[0] = true;
        queue<int> q, next;
        q.push(0);
        while(!q.empty()) {
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int room : rooms[cur]) {
                    if (!dp[room]) next.push(room);
                }
                dp[cur] = true;
            }
            swap(q, next);
        }
        for (const bool &open : dp) {
            if (!open) return false;
        }
        return true;
    }
};