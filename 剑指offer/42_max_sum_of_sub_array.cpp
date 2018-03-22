#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_sum(const vector<int> &v);
int max_sum_greedy(const vector<int> &v);
int max_sum_dp(const vector<int> &v);

int main() {
	vector<int> v = {1, 0, -2, -10, 3};
	cout << max_sum(v) << endl;
	cout << max_sum_dp(v) << endl;
	cout << max_sum_greedy(v) << endl; 
	return 0;
}


// BF
int max_sum(const vector<int> &v) {
	int max_sum = INT_MIN;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i, sum = 0; j < v.size(); j++) {
			sum += v[j]; max_sum = max(max_sum, sum);
		}
	}
	return max_sum;
}


// DP
int max_sum_dp(const vector<int> &v) {
	vector<int> dp(v.size() + 1, 0);
	for (int i = 1; i <= v.size(); i++) dp[i] = dp[i - 1] <= 0 ? v[i - 1] : dp[i - 1] + v[i - 1];
	return dp[v.size()];
}


// 贪心算法是DP算法的简化
int max_sum_greedy(const vector<int> &v) {
	int max_sum = INT_MIN, sum = 0;
	for (int n : v) {
		sum += n; max_sum = max(max_sum, sum);
		if (sum < 0) sum = 0;
	}
	return max_sum;
}