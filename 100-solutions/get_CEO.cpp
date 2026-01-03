//
//  main.cpp
//  xinxinjie_project
//
//  Created by 赵明星 on 2016/12/23.
//  Copyright © 2016年 赵明星. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string get_CEO(string& s);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s = "CCCEEEOOO";
    cout << get_CEO(s) << endl;
    return 0;
}


string get_CEO(string& s) {
    string res;
    vector<int> vec(3, 0);
    for (auto c : s) {
        if (c == 'C') {
            vec[0] ++;
        } else if (c == 'E') {
            vec[1] ++;
        } else {
            vec[2] ++;
        }
    }
    while (vec[0] > 0 || vec[1] > 0 || vec[2] > 0) {
        if (vec[0] > 0) {
            res.push_back('C');
            vec[0] --;
        }
        if (vec[1] > 0) {
            res.push_back('E');
            vec[1] --;
        }
        if (vec[2] > 0) {
            res.push_back('O');
            vec[2] --;
        }
    }
    return res;
}
