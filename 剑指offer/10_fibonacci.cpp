#include <iostream>

using namespace std;

int fibonacci(int n);

int main() {
	cout << fibonacci(1) << endl;
	return 0;
}

int fibonacci(int n) {
	int pre = 0, cur = 1, tmp = 0;
	while (n--) {
		tmp = cur;
		cur += pre;
		pre = cur;
	}
	return pre;
}