#include <iostream>
#include <vector>

using namespace std;

int numSubarrayBoundedMax(vector<int>& A, int L, int R);

int main() {
    vector<int> nums = {73,55,36,5,55,14,9,7,72,52};
    cout << numSubarrayBoundedMax(nums, 32, 69) << endl;
    return 0;
}



int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    if (A.size() == 0) return 0;
    vector<int> dp(A.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        if (A[i] <= R && A[i] >= L) dp[i] = 1;
        else if (A[i] < L) dp[i] = -1;
    }
    int sum = dp[0] < 0 ? 0 : dp[0];
    for (int i = 1; i < A.size(); i++) {
        if (dp[i] < 0) dp[i] = dp[i - 1] > 0 ? dp[i - 1] : dp[i] + dp[i - 1];
        else if (dp[i] > 0) dp[i] += abs(dp[i - 1]);
        sum += dp[i] < 0 ? 0 : dp[i];
    }
    for (int i : dp) cout << i << " ";
    cout << endl;
    return sum;
}