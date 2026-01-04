#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxPriceWithLimit(vector<int> &prices, int limit);

int main() {
    vector<int> prices = {4,6};
    cout << maxPriceWithLimit(prices, 10) << endl;

    return 0;



}

int maxPriceWithLimit(vector<int> &prices, int limit) {
    if (prices.size() == 0) {
        return 0;
    }
    if (limit < 0) {
        return 0;
    }
    vector<vector<int>> dp(prices.size() + 1, vector<int>(limit + 1, 0));
    // 状态转移函数：dp[i][j] 表示只用前 i 个商品预算为 j 时能获取的最大价值，dp[i][j] = max(dp[i-1][j], dp[i][j - prices[i]] + prices[i])
    for (int i = 1; i <= prices.size(); i++) {
        for (int j = 1; j <= limit; j++) {
            if (j >= prices[i-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-prices[i-1]] + prices[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[prices.size()][limit];
}
