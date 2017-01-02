//
//  main.cpp
//  test
//
//  Created by 赵明星 on 2016/12/28.
//  Copyright © 2016年 赵明星. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    char s[] = "hellodhaughuahudehweufhauiheuifa";
    char* s_1 = s + 1;
    cout << s_1[-1] << endl;
    char* q = new char[10];
    char* p;
    p = s;
    cout << "sizeof(s): " << sizeof(s) << endl;
    cout << "sizeof(p): " << sizeof(p) << endl;
    cout << "sizeof(*p): " << sizeof(*p) << endl;
    cout << "strlen(p): " << strlen(p) << endl;
    cout << "strlen(s): " << strlen(s) << endl;
    cout << "sizeof(q): " << sizeof(q) << endl;
    cout << "strlen(q): " << strlen(q) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
