#include <iostream>
#include <stack>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxWater(vector<int> &nums);

int main() {
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << maxWater(nums) << endl;
    return 0;
}


int maxWater(vector<int> &nums) {
    int res = 0;
    stack<int> s;
    for (int i = 0; i < nums.size(); i++) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            int buttom = s.top();
            s.pop();
            if (!s.empty()) {
                int left = s.top(), right = i;
                int width = right - left - 1;
                int height = min(nums[left], nums[right]) - nums[buttom];
                res += width * height;
            }
        }
        s.push(i);
    }
    return res;
}
