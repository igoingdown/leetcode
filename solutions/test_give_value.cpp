#include <iostream>

using namespace std;

int foo() {
	int a = 10;
	return a = 9;
}

int main(void) {
	cout << foo() << endl;
}