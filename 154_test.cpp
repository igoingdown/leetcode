//
//  main.cpp
//  154-test
//
//  Created by 赵明星 on 2016/12/12.
//  Copyright © 2016年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> vec = {1, 2, 3};
    auto iter = min_element(vec.begin(), vec.end());
    cout << *iter << endl;
    std::cout << "Hello, World!\n";
    int tmp = min(1, 3);
    cout << tmp << endl;
    return 0;
}
