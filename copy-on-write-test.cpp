//
//  main.cpp
//  copy-on-write-test
//
//  Created by 赵明星 on 2017/1/2.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string s1 = "hello world";
    //string s2 = s1;
    string s2(s1);
    cout << "sharing memory" << endl;
    printf("\ts1 address: %x\n", s1.c_str());
    printf("\ts2 address: %x\n", s2.c_str());
    
    // cout << "s1 address: " << s1.c_str() << endl;
    // cout << "s2 address: " << s2.c_str() << endl;
    
    s1[1] = 'l';
    s2[1] = 'm';
    cout << "after modified" << endl;
    printf("\ts1 address: %x\n", s1.c_str());
    printf("\ts2 address: %x\n", s2.c_str());
    // cout << "s1 address: " << s1.c_str() << endl;
    // cout << "s2 address: " << s2.c_str() << endl;
    
    cout << "Hello, World!\n";
    return 0;
}
