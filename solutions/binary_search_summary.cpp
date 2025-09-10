//
//  main.cpp
//  binary_search_lower_bound
//
//  Created by 赵明星 on 2016/12/28.
//  Copyright © 2016年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int binary_search_lower_bound(const vector<int> & nums, int k);
int binary_search_higher_bound(const vector<int> & nums, int k);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {1, 2, 3, 3, 3, 4};
    cout << binary_search_lower_bound(nums, 3) << endl;
    cout << binary_search_higher_bound(nums, 3) << endl;
    return 0;
}


int binary_search_lower_bound(const vector<int> & nums, int k){
    int low = 0, high = nums.size() - 1; //区别在这里！这里high向下取整
    while (low < high) {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] < k) {            //先拿出最好判断的！
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int binary_search_higher_bound(const vector<int> & nums, int k){
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + ((high + 1 - low) >> 1); //关键在这里！这里high向上取整
        // cout << low << " " << mid << " " << high << endl;
        if (nums[mid] > k) {            //先拿出最好判断的！
            high = mid - 1;
        } else {
            low = mid;
        }
    }
    return low;
}
