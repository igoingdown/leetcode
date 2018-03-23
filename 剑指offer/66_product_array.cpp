#include <iostream>
#include <vector>

using namespace std;

void multiply(const vector<int> &arr1, vector<int> &arr2);

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> a = {1, 2, 3, 4}, b(a.size());
	multiply(a, b);
	for (int num : b) cout << num << " ";
	cout << endl;
	return 0;
}


void multiply(const vector<int> &arr1, vector<int> &arr2) {
	if (arr1.size() < 2) return;
	arr2[0] = 1;
	for (int i = 1; i < arr1.size(); i++) {
		arr2[i] = arr2[i - 1] * arr1[i - 1];
	}
	int tmp = 1;
	for (int i = arr1.size() - 2; i >= 0; i--) {
		tmp *= arr1[i + 1];
		arr2[i] *= tmp;
	}
}