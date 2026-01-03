#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> kthPermutation(int n, int k);

int main() {
	for (int n : kthPermutation(3, 3)) cout << n << endl;
	return 0;
}

vector<int> kthPermutation(int n, int k) {
	vector<int> res;
	unordered_set<int> s;
	int combinations = 1;
	for (int i = 1; i <= n; i++) combinations *= i;
	for (int i = 1; i <= n; i++) {
		if (combinations == 1) {
			for (int j = 1; j <= n; j++) {
				if (s.find(j) == s.end()) {
					res.push_back(j);
					return res;
				}
			}
		}
		combinations /= (n + 1 - i);
		int cur = 1;
		while (cur <= n && combinations * cur <= k) cur++;
		k -= (cur - 1) * combinations;
		while (cur <= n + 1 && s.find(cur - 1) != s.end()) cur++;
		res.push_back(cur - 1);
		s.insert(cur - 1);
	}
	return res;
}
