#include <iostream>
#include <vector>

using namespace std;

int dfs(std::vector<int>& coins, int amount);
bool myCompare(int a, int b);
int coinChange(vector<int>& coins, int amount);

int main(int argc, char const *argv[])
{
    /* code */
    int a[3] = {10, 25, 30};
    std::vector<int> v(a, a + 3);
    cout << coinChange(v, 50) << endl;
    return 0;
}
    
int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), myCompare);
    return dfs(coins, amount);
}

bool myCompare(int a, int b) {
    return a > b;
}

int dfs(std::vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    for (int n : coins) {
        if (amount >= n) {
            int tmp = dfs(coins, amount - n);
            if(tmp >= 0) return tmp + 1;
        }
    }
    return -1;
}
