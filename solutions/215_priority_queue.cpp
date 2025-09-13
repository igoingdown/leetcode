#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int findKthLargestNum(vector<int> &nums, int k) {
    priority_queue<int,vector<int>, greater<int>> q;
    for (int n : nums) {
        if (q.size() < k) {
            q.push(n);
        } else {
            if (q.top() <= n) {
                q.push(n);
                q.pop();
            }
        }
    }
    return q.top();
}

int main() {
    // Test example 1
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Test 1: findKthLargestNum({3, 2, 1, 5, 6, 4}, 2) = " << findKthLargestNum(nums1, k1) << endl;
    
    // Test example 2
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "Test 2: findKthLargestNum({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4) = " << findKthLargestNum(nums2, k2) << endl;
    
    // Test example 3 - edge case
    vector<int> nums3 = {1};
    int k3 = 1;
    cout << "Test 3: findKthLargestNum({1}, 1) = " << findKthLargestNum(nums3, k3) << endl;
    
    return 0;
}
