//
//  main.cpp
//  81
//
//  Created by 赵明星 on 2017/2/17.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1, 1, 3, 1};
    if (search(nums, 3)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}


bool search(vector<int>& nums, int target){
    if (nums.size() == 0) {
        return false;
    }
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[mid] < nums[low]) {
            if (nums[mid] < target && nums[high] >= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } else if (nums[mid] > nums[low]) {
            if (nums[low] <= target && nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            low++;
        }
    }
    return nums[low] == target ? true : false;
}
