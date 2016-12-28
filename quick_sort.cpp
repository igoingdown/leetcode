//
//  main.cpp
//  quick_sort
//
//  Created by 赵明星 on 2016/12/28.
//  Copyright © 2016年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> & nums, int l, int r);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {2, 2, 10, 1, 1, 2, 5, -1};
    quick_sort(nums, 0, nums.size() - 1);
    for (auto n : nums) {
        cout << n << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}


void quick_sort(vector<int> & nums, int l, int r) {
    swap(nums[l], nums[l + (r - l) / 2]);
    if (l < r) {
        int i = l, j = r, x = nums[l];
        while (i < j) {
            while (i < j && nums[j] >= x) {
                j--;
            }
            if (i < j) {
                nums[i++] = nums[j];
            }
            while (i < j && nums[i] <= x) {
                i++;
            }
            if (i < j) {
                nums[j--] = nums[i];
            }
        }
        nums[i] = x;
        quick_sort(nums, l, i - 1);
        quick_sort(nums, i + 1, r);
    }
}
