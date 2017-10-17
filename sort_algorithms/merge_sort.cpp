#include <iostream>
#include <vector>

using namespace std;

void mergeArray(vector<int>& s, int l, int m, int r);
void mergeSort(vector<int>& s, int l, int r);

int main(void) {
	int a[7] = {10, 3, 13, 4, 2, 1, 37};
	vector<int> v(a, a + 7);
	mergeSort(v, 0, 7);
	for (int n : v) {
		cout << n << " ";
	}
	cout << endl;
	return 0;
}

void mergeArray(vector<int>& s, int l, int m, int r) {
	int tb = 0, lb = l, rb = m;
	vector<int> tmp(r - l, 0);
	while (lb < m && rb < r) {
		if (s[lb] < s[rb]) {
			tmp[tb++] = s[lb++];
		} else {
			tmp[tb++] = s[rb++];
		}
	}
	while(lb < m) {
		tmp[tb++] = s[lb++];
	}
	while (rb < r) {
		tmp[tb++] = s[rb++];
	}
	for (int i = 0; i < tb; i++) {
		s[l + i] = tmp[i];
	}
}


void mergeSort(vector<int>& s, int l, int r) {
	int mid = l + ((r - l) >> 1);
	if (mid > l) {
		mergeSort(s, l, mid);
		mergeSort(s, mid, r);
		mergeArray(s, l, mid, r);
	}
}