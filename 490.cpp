#include <iostream>
# include <vector>

using namespace std;

void bubble_sort(vector<int>& s);
void bubble_sort_with_check(vector<int>& s);


int main(int argc, char const *argv[])
{
	/* code */
	char[6][6] = 
	{
		{'.', 'X', '.', '.', '.', 'X'}, 
		{'.', '.', '.', 'X', '.', 'X'}, 
		{'X', 'X', '.', 'X', '.', '.'}, 
		{'.', 'X', 'X', 'X', '.', 'X'}, 
		{'.', '.', '.', '.', '.', 'X'}, 
		{'.', '.', '.', '.', '.', '.'}
	}
	int a[5] = {3, 4, 6, 9, 10};
	vector<int> b(a, a + 5);
	bubble_sort(b);
	for (int i = 0; i < 5; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}


void bubble_sort(vector<int>& s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {  // 趟数
		cout << i << endl;
		for (int j = 1; j < n - i; j++) {   // pos
			if (s[j] > s[j - 1]) {
				swap(s[j], s[j - 1]);
			}
		}
	}
}

void bubble_sort_with_check(vector<int>& s) {
	int n = s.size();
	for (int  i = 0; i < n; i++) {
		cout << i << endl;
		bool all_sorted = true;
		for (int j = 1; j < n - i; j++) {
			if (s[j] < s[j - 1]) {
				swap(s[j], s[j - 1]);
				all_sorted = false;
			}
		}
		if (all_sorted) {
			return;
		}
	}
}