#include <iostream>

using namespace std;

double mySqrt(int x);

int main() {
	cout << mySqrt(2) << endl;
	return 0;
}

double mySqrt(int x) {
    double x0 = 1, x1;
    while (1) {
    	x1 = x0 - (x0 * x0 - x) / (2 * x0);
    	if ((x1 - x0) < 1e-8 && (x1 - x0) > -1e-8) return x1;
    	else x0 = x1;
    }
    return 0;
}