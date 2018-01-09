#include <iostream>
#include <vector>

using namespace std;
void max_heapify(vector<int>& v, int b, int e);
void heap_sort(vector<int>& v);

void max_heapify(vector<int>& v, int b, int e) {
	int cur = b, child = 2 * b + 1;
	while (child < e) {
		if (child + 1 < e && v[child] < v[child + 1]) child++;
		if (v[cur] < v[child]) {
			swap(v[cur], v[child]);
			cur = child;
			child = child * 2 + 1;
		} else break;
	}
}

void heap_sort(vector<int>& v) {
	int n = v.size();
	for (int i = n / 2 - 1; i >= 0; i--) max_heapify(v, i, n);
	for (int i = n - 1; i > 0; i--) {
		swap(v[0], v[i]);
		max_heapify(v, 0, i);
	}
}

int main(void) {
	int a[5] = {1, 4, 2, 3, 0};
	vector<int> v(a, a + 5);
	heap_sort(v);
	for (int n : v) cout << n << endl;
	return 0;
}