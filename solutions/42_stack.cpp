#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(vector<int> &nums);

int main() {
    // 原始测试用例
    vector<int> nums1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Test 1 (标准用例): " << trap(nums1) << " (期望: 6)" << endl;
    
    // 边界条件测试
    vector<int> nums2 = {};
    cout << "Test 2 (空数组): " << trap(nums2) << " (期望: 0)" << endl;
    
    vector<int> nums3 = {1};
    cout << "Test 3 (单元素): " << trap(nums3) << " (期望: 0)" << endl;
    
    vector<int> nums4 = {1,2,3,4,5};
    cout << "Test 4 (单调递增): " << trap(nums4) << " (期望: 0)" << endl;
    
    vector<int> nums5 = {5,4,3,2,1};
    cout << "Test 5 (单调递减): " << trap(nums5) << " (期望: 0)" << endl;
    
    vector<int> nums6 = {5,5,5,5};
    cout << "Test 6 (全部相等): " << trap(nums6) << " (期望: 0)" << endl;
    
    vector<int> nums7 = {4,2,3};
    cout << "Test 7 (简单凹槽): " << trap(nums7) << " (期望: 1)" << endl;
    
    vector<int> nums8 = {2,0,2};
    cout << "Test 8 (两侧等高): " << trap(nums8) << " (期望: 2)" << endl;
    
    vector<int> nums9 = {0,1,0,2,1,0,1,3,2,1,2,1,1,0,2,1,0,2,1,3,2,1,2,1};
    cout << "Test 9 (复杂用例): " << trap(nums9) << " (期望: 13)" << endl;
    
    return 0;
}

int trap(vector<int> &nums) {
    int res = 0;
    stack<int> s;
    for (int i = 0; i < nums.size(); i++) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            int j = s.top();
            s.pop();
            if (!s.empty()) {
                res += (i - s.top() - 1) * (min(nums[s.top()], nums[i]) - nums[j] );
            }
        }
        s.push(i);
    }
    return res;
}
