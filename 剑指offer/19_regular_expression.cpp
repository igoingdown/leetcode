#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool is_match(const string &s1, const string &s2);


int main() {
	string s1, s2; cin >> s1 >> s2;
	if (is_match(s1, s2)) cout << "Y" << endl;
	else cout << "N" << endl;
	return 0;
}


bool is_match(const string &s1, const string &s2) {
	int m = s1.size(), n = s2.size();
	vector<vector<bool>> dp(m + 1, vector<bool> (n + 1));
	dp[0][0] = true;
	for (int j = 1; j <= n; j++) dp[0][j] = j > 1 && dp[0][j - 2] && s2[j - 1] == '*';
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s2[j - 1] == '*') dp[i][j] = j > 1 && (dp[i][j - 2] || ((s2[j - 2] == '.' || s2[j - 2] == s1[i - 1]) && dp[i - 1][j])); 
			else dp[i][j] = dp[i - 1][j - 1] && (s1[i - 1] == s2[j - 1] || s2[j - 1] == '.');
			cout << dp[i][j] << endl;
		}
	}
	return dp[m][n];
}

