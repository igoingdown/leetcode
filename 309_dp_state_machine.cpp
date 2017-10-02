class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        if (s < 2) {
            return 0;
        }
        vector<int> s0(s, 0), s1(s, 0), s2(s, 0);
        s0[0] = 0;
        s1[0] = -prices[0];
        s2[0] = INT_MIN;
        for (int i = 1; i < s; i++) {
            s0[i] = max(s0[i - 1], s2[i - 1]);
            s1[i] = max(s0[i - 1] - prices[i], s1[i - 1]);
            s2[i] = s1[i - 1] + prices[i];
        }
        return max(s0[s - 1], s2[s - 1]);
    }
};