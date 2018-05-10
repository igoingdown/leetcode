#include <iostream>
#include <vector>

using namespace std;

void multiply(const vector<int> &arr1, vector<int> &arr2);
void myMultipy(const vector<int> &arr1, vector<int> &arr2);

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> a = {1, 2, 3, 4}, b(a.size(), 1);
	multiply(a, b);
	// myMultipy(a, b);
	for (int num : b) cout << num << " ";
	cout << endl;
	return 0;
}


void multiply(const vector<int> &arr1, vector<int> &arr2) {
	if (arr1.size() < 2) return;
	for (int i = 1; i < arr1.size(); i++) {
		arr2[i] = arr2[i - 1] * arr1[i - 1];
	}
	int tmp = 1;
	for (int i = arr1.size() - 2; i >= 0; i--) {
		tmp *= arr1[i + 1];
		arr2[i] *= tmp;
	}
}

void myMultipy(const vector<int> &arr1, vector<int> &arr2) {
	int n = arr1.size();
	if (n < 2) return;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) arr2[j] *= (i == j ? 1 : arr1[i]);
	}
}