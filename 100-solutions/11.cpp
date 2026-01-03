//
//  main.cpp
//  11
//
//  Created by 赵明星 on 2017/3/4.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> n = {1, 1};
    cout << maxArea(n) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1, water = 0, h = 0, res = 0;
    while (l < r) {
        h = min(height[l], height[r]);
        water = (r - l) * h;
        res = max(water, res);
        while (l < r && height[l] <= h) l++;
        while (l < r && height[r] <= h) r--;
    }
    return res;
}









