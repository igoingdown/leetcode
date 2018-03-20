#include <iostream>
#include <string>

using namespace std;

void func(int a);
int foo(int aa);

int main() {
	int (*fp) (int) = NULL;
	fp = &foo;
	int a = fp(10);
	cout << a << endl;
	return 0;
}



void func(int a) {
	cout << "a" << endl;
}


int foo(int aa) {
	cout << "aa" << endl;
	return 0;
}


