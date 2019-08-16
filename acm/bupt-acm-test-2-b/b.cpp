#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


int  main(void) {
	ifstream infile;
	infile.open("test.txt");
	int t;
	infile >> t;
	while (t--) {
		int n;
		infile >> n;
		vector<string> v;
		char c;
		infile.get(c);
		for (int i = 0; i < 2; i++) {
			char cstr[n + 1];
			infile.getline(cstr, n + 1);
			string s(cstr);
			v.push_back(s);
		}
		unordered_set<char> c_s1;
		unordered_set<char> c_s2;

		// 存放的是index到index的映射。
		vector<int> v_1(36, -1);
		vector<int> v_2(36, -1);
		pair<char, char> f;
		for (int i = 0; i < n; i++) {
			if ((v[0][i] <= '9' && v[0][i] >= '0') ^ (v[1][i] <= '9' && v[1][i] >= '0')) {
				// 一个字母，一个是数字
				if (v[0][i] <= '9' && v[0][i] >= '0') {
					// 第一个是数字
					v_2[v[1][i] - 'A' + 10] = v[0][i];
					v_1[v[0][i] - '0'] = v[1][i];
				} else {
					// 第二个是数字
					v_1[v[0][i] - 'A' + 10] = v[1][i];
					v_2[v[1][i] - '0'] = v[0][i];
				}
			} else {
				c_s1.insert(v[0][i]);
				c_s2.insert(v[1][i]);
			}
		}
		int res = 1;
		for (auto i = c_s1.begin(); i != c_s1.end(); i++) {
			bool flag = true;
			char j = *i;
			while (v_1[j - 'A' + 10] > 0) {
				char temp = v_1[j - 'A' + 10];
				if (temp >= '0' & temp <= '9') {
					flag = false;
					break;
				} else {
					j = v_2[temp];
					if (j < 0) {
						break;
					}
				}
			}
			if (flag) {
				res *= 10;
			}
		}
		cout << res << endl;
	} 
	return 0;
}



















