class Solution {
private:
    int helper(const vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        for (int n : coins) {
            if (amount >= n) {
                int res = helper(coins, amount - n);
                if( res >= 0) return 1 + res;
            }
        }
        return -1;
    }
public:
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), myComp);
        return helper(coins, amount);
    }
    
    static bool myComp(int i, int j) {
        return i > j;
    }
};