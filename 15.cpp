//
//  main.cpp
//  15
//
//  Created by 赵明星 on 2017/3/3.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);
    for (auto vec: res) {
        cout << "[ ";
        for (auto n: vec) {
            cout << n << "\t";
        }
        cout << "]" << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}


vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    if (n < 3) {
        return res;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
            break;
        }
        if (nums[i] + nums[n - 1] + nums[n - 2] < 0) {
            continue;
        }
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < 0) {
                l++;
            } else if (sum > 0) {
                r--;
            } else {
                res.push_back({nums[i], nums[l], nums[r]});
                do {
                    l++;
                } while (l < r && nums[l] == nums[l - 1]);
                do {
                    r--;
                } while (l < r && nums[r] == nums[r + 1]);
            }
        }
    }
    return res;
}
















