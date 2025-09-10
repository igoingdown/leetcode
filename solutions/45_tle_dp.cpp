#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums);

int main() {
    vector<int> v = {2,3,1,1,4};
    cout << jump(v) << endl;
    return 0;
}


int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < n) dp[i + j] = min(dp[i] + 1, dp[i + j]);
        }
    }
    return dp[n - 1];
}