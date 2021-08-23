#include<string>
#include<iostream>
using namespace std;

int* foo() {
    int a = 10;
    return &a;
}

int main() {
    cout << *foo() << endl;;
}
