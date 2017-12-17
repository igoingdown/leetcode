#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount);

int main(int argc, char const *argv[])
{
    /* code */
    int a[3] = {1, 2, 5};
    std::vector<int> v(a, a + 3);
    cout << coinChange(v, 20) << endl;
    return 0;
}
    
int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    int res = INT_MAX;
    for (int n : coins) {
        if (amount >= n) {
            int tmp = coinChange(coins, amount - n);
            if( tmp >= 0) res = min(res, tmp + 1);
        }
    }
    return res == INT_MAX ? -1 : res;
}
