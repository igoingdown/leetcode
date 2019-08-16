#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool drawer_theory(vector<int> &nums, const int k);

int main() {
	vector<int> nums = {1, 3, 6, 7, 9, 10};
	cout << drawer_theory(nums, 13) << endl;
	return 0;
}

bool drawer_theory(vector<int> &nums, const int k) {
	if (k == 0) return false;
	vector<bool> flag(k, false);
	for (int i = 0, sum = 0; i < nums.size(); i++) {
		sum = (sum + nums[i]) % k;
		if (flag[sum]) return true;
		flag[sum] = true;
	}
	return false;
}