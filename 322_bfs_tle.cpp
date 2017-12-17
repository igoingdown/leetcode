class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<int> q, next;
        q.push(0);
        int l = 0;
        while (!q.empty()) {
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (cur == amount) return l;
                for (int coin : coins) {
                    if (coin + cur == amount) return l + 1;
                    else if (coin + cur < amount) next.push(coin + cur);
                }
            }
            swap(q, next);
            l++;
        }
        return -1;
    }
};