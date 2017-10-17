#include <iostream>
# include <vector>

using namespace std;

void insert_sort(vector<int>& s);

int main(int argc, char const *argv[])
{
	/* code */
	int a[5] = {3, 6, 2, 9, 0};
	vector<int> b(a, a + 5);
	insert_sort(b);
	for (int i = 0; i < 5; i++) {
		cout << b[i] << endl;
	}
	return 0;
}


void insert_sort(vector<int>& s) {
	int n = s.size();
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (s[i] < s[j]) {
				swap(s[j], s[i]);
			}
		}
	}
}