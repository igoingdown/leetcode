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
    char s[] = "hello";
    printf("s.strlen: %d\n", strlen(s));
    printf("s.size: %d\n", sizeof(s));
    for (int i = 0; i < sizeof(s); ++i)
    {
        printf("%x__", s[i]);
    }
    printf("\n");
    char* s_1 = s + 1;
    printf("s_1 size: %d\n", sizeof(s_1));
    for (int i = 0; i < sizeof(s_1); ++i)
    {
        printf("%x__", s_1[i]);
    }
    printf("\n");
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
    cout << "Hello, World!\n" << endl;
    cout << "what" << endl;
    
    unsigned char c = 0xff;
    printf("%d\n", ++c);
    
    signed char c1 = 0x7f;
    printf("%d\n", ++c1);
    
    signed char a = 0x7f;
    signed char b = 0x05;
    signed char d = a * b;
    printf("%x\n", d);
    
    int i = 635;
    printf("%x\n", i);
    
    unsigned int l = 0xfffffff;
    printf("%x\n", l / 4);
    
    unsigned int m = 0xfffffffc;
    unsigned int n = 0x104;
    unsigned int o = m + n;
    printf("%d\n", o);
    printf("%x\n", o);
    
    printf("%x\n", UINT_MAX);
    return 0;
}
