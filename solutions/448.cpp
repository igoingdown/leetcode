//
//  main.cpp
//  448
//
//  Created by 赵明星 on 2016/12/4.
//  Copyright © 2016年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = findDisappearedNumbers(nums);
    for(auto n: res) {
        cout << n << endl;
    }
    // cout << "\n\n" << endl;
    
    /*
    for (auto n: nums) {
        cout << n << endl;
    }
    */
    std::cout << "Hello, World!\n";
    return 0;
}


vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    for (auto n : nums) {
        nums[abs(n) - 1] = - abs(nums[abs(n) - 1]);
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            res.push_back(i + 1);
        }
    }
    return res;
}
