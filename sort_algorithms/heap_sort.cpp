#include <iostream>
#include <vector>

using namespace std;

void heap_sort(vector<int>& s);
void max_heapfy(vector<int>& s, int beg, int end);

int main(int argc, char const *argv[])
{
	/* code */
	int a[7] = {8, 5, 4, 6, 7,3,9};
	vector<int> b(a, a + 7);
	heap_sort(b);
	for (int n: b) {
		cout << n << endl;
	}
	return 0;
}


void heap_sort(vector<int>& s) {
	int n = s.size();
	for (int i = n / 2 - 1; i >= 0; i--) {
		max_heapfy(s, i, n);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(s[i], s[0]);
		max_heapfy(s, 0, i);
	}
}


void max_heapfy(vector<int>& s, int b, int e) {
	int cur = b, child = 2 * cur + 1;
	while (child < e) {
		if (child + 1 < e && s[child] < s[child + 1]) {
			child++;
		}
		if (s[cur] < s[child]) {
			swap(s[cur], s[child]);
			cur = child;
			child = child * 2 + 1;
		} else {
			break;
		}
	}
}