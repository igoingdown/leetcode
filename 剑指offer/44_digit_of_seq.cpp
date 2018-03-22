#include <iostream>
#include <cmath>


using namespace std;

int digit_of_seq(int n);


int main() {
	int n;
	while (cin >> n) cout << "res: " << digit_of_seq(n) << endl;
	return 0;
}

int digit_of_seq(int n) {
	if (n < 10) return n;
	int i = 1, c = 10;
	while (c <= n) {
		n -= c; c += i * pow(10, i - 1) * 9; i++;
	}
	int num = n / i + pow(10, i - 1);
	int exponent = pow(10, i - n % i - 1);
	return num / exponent % 10;
}