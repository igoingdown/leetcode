#include<iostream>
#include <unordered_map>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target);

int main() {
    vector<int> nums = {1,2,0,-1,3,0};
    auto res = twoSum(nums, 0);
    if (res.size() == 2) {
        cout << res[0] << "_" << res[1] << endl;
    }
    return 0;

}



vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;
    if (nums.size() < 2) {
        return res;
    }
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++) {
        m[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(target - nums[i]) != m.end() && i != m[target-nums[i]]) {
            res = {i, m[target - nums[i]]};
            break;
        }
    }
    return res;
}
