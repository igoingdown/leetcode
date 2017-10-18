#include <iostream>
#include <vector>

using namespace std;

void select_sort(vector<int>& s);

int main(int argc, char const *argv[])
{
	/* code */
	int a[5] = {1, 9, 4, 2, 3};
	vector<int> v(a, a + 5);
	select_sort(v);
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}


void select_sort(vector<int>& s) {
	int n = s.size();
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (s[i] > s[j]) {
				swap(s[i], s[j]);
			}
		}
	}
}