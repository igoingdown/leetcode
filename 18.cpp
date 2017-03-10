//
//  main.cpp
//  18
//
//  Created by 赵明星 on 2017/3/2.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);
void getPaths(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int cur, int target);


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = fourSum(nums, 0);
    for (auto vec : res) {
        cout << "[ ";
        for (auto n : vec) {
            cout << n << "\t";
        }
        cout << "]" << endl;
    }
    cout << endl;
    // std::cout << "Hello, World!\n";
    return 0;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    if (n < 4) {
        return res;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
            break;
        }
        if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) {
            continue;
        }
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                break;
            }
            if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) {
                continue;
            }
            int left = j + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    do {
                        left++;
                    }
                    while (left < right && nums[left] == nums[left - 1]);
                    do {
                        right--;
                    }
                    while (right > left && nums[right] == nums[right + 1]);
                }
            }
        }
    }
    return res;
}




























