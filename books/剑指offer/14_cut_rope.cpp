#include <iostream>
#include <vector>

using namespace std;

int cut_rope_dp(int n);
int cut_rope_greedy(int n);


int main() {

	int n; cin >> n;
	cout << cut_rope_dp(n) << endl;
	cout << cut_rope_greedy(n) << endl;
	return 0;
}


int cut_rope_dp(int n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	if (n == 3) return 2;
	vector<int> dp(n + 1);
	dp[1] = 1; dp[2] = 2; dp[3] = 3;
	for (int i = 4; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) dp[i] = max(dp[i], dp[j] * dp[i - j]);
	}
	return dp[n];
}


int cut_rope_greedy(int n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	if (n == 3) return 2;
	int count = n / 3;
	if (n - count * 3 == 1) --count;
	int res = 1, left = n - count * 3;
	while (count--) res *= 3;
	res *= (left == 0 ? 1 : left);
	return res;
}
