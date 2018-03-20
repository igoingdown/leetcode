#include <iostream>
#include <vector>

using namespace std;

int search_spiral_array(vector<int> &nums);

int main() {
	vector<int> nums = {3, 4, 5, 1, 2};
	int index = search_spiral_array(nums);
	if (index >= 0) cout << nums[index] << endl;
	else cout << "no one" << endl;
	return 0;
}

int search_spiral_array(vector<int> &nums) {
	int l = nums.size();
	if (l == 0) return -1;
	int x = nums[0], low = 0, high = l - 1, mid;
	while (low < high) {
		mid = low + ((high - low) >> 1);
		if (nums[mid] >= x) low = mid + 1;
		else high = mid;
	}
	return nums[low] < x ? low : 0;
}
