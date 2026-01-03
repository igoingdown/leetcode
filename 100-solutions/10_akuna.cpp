#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool isMatch(string& s, string& p);

int main() {
	string s = "aaba", p = ".a*";
	if (isMatch(s, p)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

bool isMatch(string& s, string& p) {
	int ss = s.size(), ps = p.size();
	vector<vector<bool>> dp(ss + 1, vector<bool> (ps + 1, false));
	dp[0][0] = true;
	for (int j = 1; j <= ps; j++) {
		if (j > 1 && p[j - 2] == '.' && p[j - 1] == '*' && dp[0][j - 2]) dp[0][j] = true;
	}
	for (int i = 1; i <= ss; i++) {
		for (int j = 1; j <= ps; j++) {
			if (p[j - 1] == '*') dp[i][j] = j > 1 && p[j - 2] == '.' && (dp[i][j - 2] || dp[i - 1][j]);
			else if (p[j - 1] == '?') dp[i][j] = j > 1 && p[j - 2] == '.' && (dp[i][j - 2] || dp[i][j - 1]);
			else dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
		}
	}
	return dp[ss][ps];
}