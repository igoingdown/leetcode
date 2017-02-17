//
//  main.cpp
//  78
//
//  Created by 赵明星 on 2017/2/17.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void test(vector<int>& v1, vector<int>& v2);

vector<vector<int>> subsets(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> emp(0);
    emp.push_back(10);
    cout << emp.size() << endl;
    vector<vector<int>> temp = {emp};
    cout << temp.size() << endl;
    std::cout << "Hello, World!\n";
    
    vector<int> v2(10);
    test(emp, v2);
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    for (auto s: res) {
        printf("[");
        for (auto n: s) {
            printf("%d\t", n);
        }
        printf("]\n");
    }
    return 0;
}

void test(vector<int>& v1, vector<int>& v2) {
    printf("%x\n", &v1);
    printf("%x\n", &v2);
    v1 = v2;
    printf("%x\n", &v1);
    printf("%x\n", &v2);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> emptySet(0);
    vector< vector<int> > res = {emptySet};
    if (nums.size() == 0) {
        return res;
    }
    vector<vector<int>> init(res);
    
    while (nums.size() != 0) {
        int num = nums.back();
        nums.pop_back();
        init = res;
        for (auto s: init) {
            s.push_back(num);
            res.push_back(s);
        }
    }
    return res;
    
}


















