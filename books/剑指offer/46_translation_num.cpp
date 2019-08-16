#include <iostream>
#include <vector>
#include <string>

using namespace std;

int translation_num(int num);
int translation_num(const string &str);

int main(int argc, char const *argv[])
{
	/* code */
	cout << translation_num(12258) << endl;
	return 0;
}


int translation_num(int num) {
	string str = to_string(num);
	return translation_num(str);
}

int translation_num(const string &str) {
	if (str.size() == 0) return 0;
	vector<int> dp(str.size() + 1);
	dp[0] = 1;
	for (int i = 1; i <= str.size(); i++) {
		dp[i] += dp[i - 1];
		if (i > 1) {
			string tmp = str.substr(i - 2, 2);
			dp[i] += tmp <= "25" && tmp >= "10" ? dp[i - 2] : 0;
		}
	}
	return dp[str.size()];
}