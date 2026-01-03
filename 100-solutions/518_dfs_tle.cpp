class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        int res = 0; 
        dfs(amount, 0, res, coins, 0);
        return res;
    }
    
    void dfs(int amount, int start, int &res, const vector<int> &coins, int last) {
        if (start <= coins.size() && amount == 0 && last != 0) res++; 
        if (start >= coins.size()) return;
        for (int i = 0; i <= amount / coins[start]; i++) dfs(amount - i * coins[start], start + 1, res, coins, i);
    }
};