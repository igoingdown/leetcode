#include <iostream>
#include <string>
#include <vector>

using namespace std;



int longest_substr(const string &str);

int main(int argc, char const *argv[])
{
	/* code */
	string s;
	while (cin >> s) cout << "res : " << longest_substr(s) << endl;
	return 0;
}

int longest_substr(const string &str) {
	vector<int> v(256);
	int res = 0;
	for (int i = 0, j = 0; j < str.size(); j++){
		if (v[str[j]] > 0) {
			while (str[i] != str[j]) v[str[i++]]--;
			i++;
		}
		v[str[j]]++;
		res = max(res, j - i + 1);
	}
	return res;
}

