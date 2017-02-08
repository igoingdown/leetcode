class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCur = INT_MAX, maxPro = 0;
        for (int price: prices) {
            minCur = min(minCur, price);
            maxPro = max(maxPro, price - minCur);
        }
        return maxPro;
    }
};