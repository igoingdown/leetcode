//
//  main.cpp
//  leetcode 414
//
//  Created by 赵明星 on 2016/12/5.
//  Copyright © 2016年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int thirdMax(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {2, 3, 2, 1};
    int res = thirdMax(nums);
    cout << res << endl;
    std::cout << "Hello, World!\n";
    return 0;
}

int thirdMax(vector<int>& nums) {
    if (! nums.size()) {
        return 0;
    } else if (nums.size() == 1) {
        return nums[0];
    } else if (nums.size() == 2) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    int max = INT_MIN;
    int sec_max = INT_MIN;
    int thrd_max = INT_MIN;
    for (auto n : nums) {
        //cout << "what?" << endl;
        if (n > max) {
            cout << n << " max " << max << endl;
            thrd_max = sec_max;
            sec_max = max;
            max = n;
        } else if (n > sec_max && n < max) {
            cout << n << " sec " << sec_max << endl;
            thrd_max = sec_max;
            sec_max = n;
        } else if (n > thrd_max && n < sec_max) {
            cout << n << " thrd " << thrd_max << endl;
            thrd_max = n;
        }
    }
    return thrd_max;
}



