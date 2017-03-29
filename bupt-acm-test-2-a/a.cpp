#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;


int  main(void) {
	ifstream infile;
	infile.open("test.txt");
	int t;
	infile >> t;
	while (t--) {
		int n, m, k;
		infile >> n >> m >> k;
		vector<string> v;
		char c;
		infile.get(c);
		int n_c = n;
		while (n_c--) {
			char cstr[m + 1];
			infile.getline(cstr, m + 1);
			string s(cstr);
			v.push_back(s);
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == 'O' && i + 1 >= k && i + 1 <= n - k + 1 && j + 1 >= k && j + 1 <= m - k + 1) {
					bool flag = true;
					for (int x = 0; x < n; x++) {
						for (int y = 0; y < m; y++) {
							if (abs(x - i) + abs(y - j) <= k - 1) {
								if (v[x][y] != 'O') {
									flag = false;
								}
							}
						}
					}
					if (flag) {
						res++;
					}
				}
			}
		}
		cout << res << endl;
	} 
	return 0;
}



















