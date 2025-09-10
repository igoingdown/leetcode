#include <iostream>
#include <vector>
#include <cfloat>
#include <cmath>

using namespace std;

float mysqrt(float x) ;

int main() {
	cout << mysqrt(2.0) << endl;
	return 0;
}
// 牛顿法求平方根

// f(x) = x^2 - target
// 切线方程 2 * x_n * (x - x_n) = y - y_n
// 切线与x轴交点为: x_(n+1) = x_n - (x_n * x_n - target) / (2 * x_n)
// 于是更新方式为: x_n -= (x_n * x_n - target) / (2 * x_n)


float mysqrt(float x) {
	float x1 = x + 0.25, x2;
	while (fabs((x1 * x1 - x)) > FLT_EPSILON) {
		cout << x1 << endl;
		x1 -= (x1 * x1 - x) / (2 * x1);
	}
	return x1;
}