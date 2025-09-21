#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSubSum(vector<int> &nums);

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubSum(nums) << endl;
    return 0;
}


int maxSubSum(vector<int> &nums) {
    int res = INT_MIN, s = 0;
    for (auto n : nums) {
        if (s < 0) {
            s = n;
        } else {
            s += n;
        }
        res = max(s, res);
    }
    return res;
}

