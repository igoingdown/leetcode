#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


double double_power(double base, int exponent);

int main() {
	double base; int exponent;
	cin >> base >> exponent;
	cout << double_power(base, exponent) << endl;
	return 0;
}

double double_power(double base, int exponent) {
	assert(!(base < 1e-10 && base > -1e-10 && exponent < 0));
	if (exponent == 0) return 1;
	if (exponent == 1) return base;
	int signal = exponent < 0 ? -1 : 1;
	long long e = exponent; e = labs(e);
	double res = 1.0;
	while (e) {
		res *= (e & 1) ? base : 1.0;
		base *= base; e >>= 1;
	}
	return signal < 0 ? 1.0 / res : res;
}
