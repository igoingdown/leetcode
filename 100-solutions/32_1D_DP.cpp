#include <iostream>
#include <vector>
#include <string> 

using namespace std;

int longestValidParentheses(string s);

int main(int argc, char const *argv[])
{
	/* code */
	string s("()(())");
	cout << longestValidParentheses(s) << endl;
	return 0;
}

int longestValidParentheses(string s) {
    int ss = s.size(), res = 0;
    vector<int> dp(ss + 1, 0);
    for (int i = 1; i <= ss; i++) {
        if (s[i - 1] == ')') {
            if (i > 1 && s[i - 2] == '(') dp[i] = dp[i - 2] + 2;
            else if (i > 2 && s[i - dp[i - 1] - 2] == '(') dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2;
            res = max(res, dp[i]);
        }
    }
    for (int c : dp) cout << c << "\t";
    cout << endl;
    return res;
}