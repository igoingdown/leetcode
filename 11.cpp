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
    int i = 0, j = height.size() - 1, water = 0;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, h * (j - i));
        while (i < j && height[i] <= h) {
            i++;
        }
        while (i < j && height[j] <= h) {
            j--;
        }
    }
    return water;
}











