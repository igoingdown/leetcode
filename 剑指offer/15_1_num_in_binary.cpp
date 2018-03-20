#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


int one_num(int x);
int one_num_no_exception(int x);
int one_num_efficient(int x);

int main() {
	int x; cin >> x;
	// cout << one_num(x) << endl;
	cout << one_num_no_exception(x) << endl;
	cout << one_num_efficient(x) << endl;
	return 0;
}


// dead loop when x < 0
int one_num(int x) {
	int res = 0;
	while (x) {
		res += (x & 1); x >>= 1;
		printf("%x\n", x);
	}
	return res;
}


int one_num_no_exception(int x) {
	int res;
	for (int i = 0; i < sizeof(x) * 8; i++) {
		res += ((x & (1 << i)) == 0 ? 0 : 1);
	} 
	return res;
}

int one_num_efficient(int x) {
	int count = 0;
	while (x) {
		++count;
		x &= (x - 1);
	}
	return count;
}
