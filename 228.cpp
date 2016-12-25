//
//  main.cpp
//  228
//
//  Created by 赵明星 on 2016/12/8.
//  Copyright © 2016年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {};
    for (auto s : summaryRanges(nums)) {
        cout << s << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}


vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res(0);
    if (! nums.size()) {
        return res;
    }
    int beg = 0, i = 1;
    while(i < nums.size()) {
        i = beg + 1;
        while(nums[i] == nums[i - 1] + 1 && i < nums.size()) {
            i++;
        }
        if (beg != i - 1) {
            res.push_back(to_string(nums[beg]) + "->" + to_string(nums[i - 1]));
        } else {
            res.push_back(to_string(nums[beg]));
        }
        beg = i;
        //cout << i << endl;
    }
    if (beg != i) {
        if (beg == i - 1) {
            res.push_back(to_string(nums[beg]));
        } else {
            res.push_back(to_string(nums[beg]) + "->" + to_string(nums.size()- 1));
        }
       
    }
    return res;
}
