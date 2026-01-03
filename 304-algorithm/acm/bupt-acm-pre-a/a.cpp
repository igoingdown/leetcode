#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;


int  main(void) {
	ifstream infile;
	infile.open("test.txt");
	int t;
	infile >> t;
	while (t--) {
		int n;
		infile >> n;
		vector<long long> v;
		int n_c = n;
		while (n_c--) {
			long long x;
			infile >> x;
			v.push_back(x);
		}
		sort (v.begin(), v.end());
		long long res = 0;
		int s = v.size();

		for (int i = 0; i < s - 2; i++) {
			cout << i << endl;
            if (i > 0 && v[i] == v[i - 1]) {
                continue;
            }
            if (v[i] + v[i + 1] + v[i + 2] > 0) {
                break;
            }
            if (v[i] + v[s - 2] + v[s - 1] < 0) {
                continue;
            }
            int l = i + 1, r = s - 1;
            while (l < r) {
                long long sum = v[i] + v[l] + v[r];
                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                	long long vi = v[i], vl = v[l], vr = v[r];
                    res += (vi * vi) + (vl * vl) + (vr * vr);
                    do {
                        l++;
                    } while(v[l] == v[l - 1]);
                    do {
                        r--;
                    } while(v[r] == v[r + 1]);
                }
            }
        }
        cout << res << endl;
        cout << res % 1000000007 << endl;
	}
	return 0;
}



















