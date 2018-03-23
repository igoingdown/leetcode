#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

void n_dice_num(int n);

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	while (cin >> n) n_dice_num(n);
	return 0;
}


void n_dice_num(int n) {
	vector<int> dp(n * 6 + 1);
	for (int i = 1; i <= 6 && i <= n * 6; i++) dp[i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int x = 6 * n; x >= 1; x--) {
			dp[x] = 0;
			for (int j = 1; j <= 6; j++) dp[x] += x - j >= 0 ? dp[x - j] : 0;
		}
	}
	if (n > 0) {
		double total = pow(6, n); double sum = 0.0;
		for (int i = 1; i <= n * 6; i++) {
			cout << i << ": " << dp[i] / total << endl;
			sum += dp[i] / total;
		}
		cout << sum << endl;
	}
}
