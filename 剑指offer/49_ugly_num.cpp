#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int ugly_num(int k);

int main(int argc, char const *argv[])
{
	/* code */
	int k; 
	while (cin >> k) cout << "res : " << ugly_num(k) << endl;
	return 0;
}


int ugly_num(int k) {
	if (k <= 0) return -1;
	vector<int> v(k); v[0] = 1;
	int index2 = 0, index3 = 0, index5 = 0;
	for (int i = 1; i < k; i++) {
		int tmp2 = v[index2] * 2, tmp3 = v[index3] * 3, tmp5 = v[index5] * 5;
		int cur = min(tmp2, min(tmp3, tmp5));
		v[i] = cur;
		if (cur == tmp2) index2++;
		if (cur == tmp3) index3++;
		if (cur == tmp5) index5++;
	}
	return v[k - 1];
}