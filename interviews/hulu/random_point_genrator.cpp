#include <iostream>
#include <cmath>

using namespace std;

pair<float, float> generator(float a1, float b1, float c1, float a2, float b2, float c2) ;

int main() {
	float a1, a2, b1, b2, c1, c2;
	cin >> a1 >> b1 >> c1;
	cin >> a2 >> b2 >> c2;
	pair<float, float> p = generator(a1, b1, c1, a2, b2, c2);
	cout << p.first * p.first + p.second * p.second << endl;
	cout << p.first << " " << p.second << endl;
	return 0;
}

pair<float, float> generator(float a1, float b1, float c1, float a2, float b2, float c2) {
	float rho = (b1 - a1) / (c1 - a1), theta = M_PI * (b2 - (c2 - a2) / 2) * 2 / (c2 - a2);
	return {rho * cos(theta), rho * sin(theta)}; 
}

