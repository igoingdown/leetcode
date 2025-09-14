#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int nthUglyNum(int n);

int main() {
    cout << "res=" << nthUglyNum(10) << endl;
    return 0;
}

int nthUglyNum(int n) {
    vector<int> dp(n, 1);
    int p2 = 0, p3 = 0, p5 = 0;
    for (int i = 1; i < n; i++) {
        int n2 = dp[p2] * 2,n3 = dp[p3] * 3, n5 = dp[p5] * 5;
        int next = min(min(n2, n3), n5);  
        dp[i] = next;
        if (n2 <= next) p2++;
        if (n3 <= next) p3++;
        if (n5 <= next) p5++;
    }
    return dp.back();
}


