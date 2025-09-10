//
//  main.cpp
//  287
//
//  Created by 赵明星 on 2016/12/7.
//  Copyright © 2016年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums);
int count (vector<int>& nums, int mid);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1, 2, 3, 4, 5, 5};
    cout << findDuplicate(nums) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}



int findDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (count(nums, mid) > mid) {
            high = mid ;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int count (vector<int>& nums, int mid) {
    int c = 0;
    for (auto n : nums) {
        if (n <= mid) {
            c++;
        }
    }
    return c;
}
