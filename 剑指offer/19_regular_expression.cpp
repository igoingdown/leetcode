#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool is_match(const string &s, const string &p);


int main() {
	string s, p; cin >> s >> p;
	if (is_match(s, p)) cout << "Y" << endl;
	else cout << "N" << endl;
	return 0;
}


bool is_match(const string &s, const string &p) {
	int m = s.size(), n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool> (n + 1));
	dp[0][0] = true;
	for (int j = 1; j <= n; j++) dp[0][j] = j > 1 && dp[0][j - 2] && p[j - 1] == '*';
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[j - 1] == '*') dp[i][j] = j > 1 && (dp[i][j - 2] || ((p[j - 2] == '.' || p[j - 2] == s[i - 1]) && dp[i - 1][j])); 
			else dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			cout << dp[i][j] << endl;
		}
	}
	return dp[m][n];
}

