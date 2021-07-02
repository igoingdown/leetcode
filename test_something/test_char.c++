#include<string>
#include<iostream>
using namespace std;

void f(int *a) {
    *a = 1;
    cout << *a << endl;
}

int main() {
    return 0;
    char a = 10;
    f(&a);
}
