#include <iostream>
#include <vector>
using namespace std;

int combinationSum4(vector<int>& nums, int target);

int main(void) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    cout << combinationSum4(nums, 10) << endl;
    return 0;
}

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int n : nums) {
            if (i - n >= 0) {
                dp[i] += dp[i - n];
            }
        }
    }
    return dp[target];
}