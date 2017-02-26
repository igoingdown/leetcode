//
//  main.cpp
//  55
//
//  Created by 赵明星 on 2017/2/25.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {2, 0, 0};
    cout << canJump(nums) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}


bool canJump(vector<int>& nums) {
    if (nums.size() < 2) {
        return true;
    }
    for (int cur = nums.size() - 2; cur >= 0; cur--) {
        if (nums[cur] == 0) {
            int jumpDis = 1;
            while (nums[cur] < jumpDis) {
                cur--;
                jumpDis++;
                if (cur < 0) {
                    return false;
                }
            }
        }
    }
    return true;
}






