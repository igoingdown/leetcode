#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator low_bound(vector<int> &v, int k);

int main() {
	vector<int> v = {1, 2, 3, 5, 6};
	auto iter = low_bound(v, 4);
	cout << *iter << endl;
	return 0;
}

vector<int>::iterator low_bound(vector<int> &v, int k) {
	int s = v.size(), low = 0, high = s - 1, mid;
	while (low < high) {
		mid = low + ((high - low) >> 1);
		if (v[mid] < k) low = mid + 1;
		else high = mid;
	}
	low = v[low] == k ? low : low - 1;
	return low < 0 ? v.end() : v.begin() + low;
}

