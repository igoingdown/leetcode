
# include <iostream>
# include <vector>

using namespace std;

int maxProfit(vector<int>& prices);
int main() {
    vector<int> prices = {1,2,3,4,5};
    cout << maxProfit(prices) << endl;
    return 0;
}
int maxProfit(vector<int>& prices) {
    int res = 0, lastBuy = -1;
    for (int i = 0; i < prices.size(); i++) {
        if (i == 0) {
            if (i + 1 < prices.size() && prices[i] < prices[i + 1]) {
                lastBuy = i;
            }  
        } else if (i == prices.size() -1) {
            if (lastBuy >= 0 && i - 1 >= 0 && prices[i] > prices[i -1]) {
                res += prices[i] - prices[lastBuy];
                lastBuy = -1;
            }
        } else {
            if (i + 1 < prices.size() && i - 1 >= 0) {
                if (prices[i] < prices[i+1] && prices[i] < prices[i - 1])  {
                    lastBuy = i;
                } else if (lastBuy >= 0 && prices[i] > prices[i -1] && prices[i] > prices[i + 1]) {
                    res += prices[i] - prices[lastBuy];
                    lastBuy = -1;
                }
            }
        }
    }
    return res;
}


