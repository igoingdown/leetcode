//
//  main.cpp
//  75
//
//  Created by 赵明星 on 2017/2/17.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& nums, int l, int r);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {0, 0};
    quickSort(nums, 0, nums.size() - 1);
    for (auto n: nums) {
        cout << n << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}


void quickSort(vector<int>& nums, int l, int r) {
    if (l < r) {
        swap(nums[l], nums[l + (r - l) / 2]);
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
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
}



