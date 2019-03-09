#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <limits>

using namespace std;

int largest_subarray_sum(vector<int> &arr) {
	int n = arr.size(), sum = 0, res = arr[0];
	for (int num : arr) {
		sum += num;
		res = max(sum, res);
		sum = (sum < 0 ? 0 : sum);
	}
	return res;
}


int largest_subarray_sum_with_upper_bound_k(vector<int> &nums, int k) {
	set<int> cums;
	cums.insert(0);
	int res = INT_MIN, cum = 0;
	for (int num : nums) {
		cum += num;
		auto iter = lower_bound(cums.begin(), cums.end(), cum - k);
		if (iter != cums.end()) {
			res = max(res, cum - *iter);
			cout << *iter << endl;
		}
		cums.insert(cum);
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> arr{2, 3,-4, 9, -19, 7, 4, 2};
	cout << largest_subarray_sum(arr) << endl;
	cout << largest_subarray_sum_with_upper_bound_k(arr, 10) << endl;
	return 0;
}
