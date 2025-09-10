class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, max_profit = 0;
        for (int p : prices) {
            min_price = min(min_price, p);
            max_profit = max(max_profit, p - min_price);
        }
        return max_profit;
    }
};