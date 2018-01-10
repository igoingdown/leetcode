#include <iostream>
#include <vector>

using namespace std;
void merge_sort(vector<int>& v, int b, int e);
void merge(vector<int>& v, int b, int mid, int e);

int main(void) {
	int a[5] = {1, 10, 4, 2, 0};
	vector<int> v(a, a + 5);
	merge_sort(v, 0, 4);
	for (int n : v) cout << n << endl;
	return 0;
}

void merge_sort(vector<int>& v, int b, int e) {
	if (b < e) {
		int mid = b + (e - b) / 2;
		merge_sort(v, b, mid);
		merge_sort(v, mid + 1, e);
		merge(v, b, mid, e);
	}
}

void merge(vector<int>& v, int b, int mid, int e) {
	vector<int> tmp;
	int lb = b, le = mid, rb = mid + 1, re = e;
	while (lb <= le && rb <= re) {
		if (v[lb] < v[rb]) tmp.push_back(v[lb++]);
		else tmp.push_back(v[rb++]);
	}
	while (lb <= le) tmp.push_back(v[lb++]);
	while (rb <= re) tmp.push_back(v[rb++]);
	for (int i = 0; i < tmp.size(); i++) v[i + b] = tmp[i];
}