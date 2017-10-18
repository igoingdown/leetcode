#include <iostream>
# include <vector>

using namespace std;

void shell_sort(vector<int>& s);

int main(int argc, char const *argv[])
{
	/* code */
	int a[5] = {3, 6, 2, 9, 0};
	vector<int> b(a, a + 5);
	hill_sort(b);
	for (int i = 0; i < 5; i++) {
		cout << b[i] << endl;
	}
	return 0;
}


void shell_sort(vector<int>& s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			if (s[j] > s[j - 1]) {
				swap(s[j], s[j - 1]);
			}
		}
	}
}