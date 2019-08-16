#include <iostream>
#include <string>
#include <vector>

using namespace std;

void partition_array(vector<int> &a, bool (*fp) (int));
bool partition_rule_1_is_odd(int a) {
	return (a & 1) == 1;
}

bool partition_rule_1_is_negative(int a) {
	return a < 0;
}

class PartitionOddAndEven {
	bool opertor() (int x) {
		return x % 2 == 0;
	}
};


int main() {
	vector<int> a = {1, 0, 2, 3};
	partition_array(a, &partition_rule_1_is_odd);
	for (int n : a) cout << n << endl;
	vector<int> b = {-1, 2, 4, -3, -5};
	partition_array(b, &partition_rule_1_is_negative);
	for (int n : b) cout << n << endl;
	return 0;
}

void partition_array(vector<int> &a, bool (*fp) (int)) {
	int low = 0, l = a.size(), high = l - 1;
	while (low < high) {
		while (low < high && fp(a[low])) low++;
		while (low < high && !fp(a[high])) high--;
		swap(a[low], a[high]);
	}
}


