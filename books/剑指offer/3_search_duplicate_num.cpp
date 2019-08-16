#include <iostream>
#include <vector>

using namespace std;


int find_dulicate_num(vector<int> &nums);
int find_dulicate_num_BS(vector<int> &nums);
int main() {
	vector<int> a;
	int n;
	while (cin >> n) a.push_back(n);
	cout << find_dulicate_num_BS(a) << endl;
	cout << " aa " << endl;
	cout << find_dulicate_num (a) << endl;
	return 0;
}

int find_dulicate_num(vector<int> &nums) {
	for (int i = 0; i < nums.size(); i++) {
		cout << abs(nums[i]) << endl;
		if (nums[abs(nums[i])] < 0) return abs(nums[i]);
		nums[abs(nums[i])] *= -1; 
	}
	// return 0; 直接返回0是不对的！要找到0所处的index，该index才是应该返回的结果。
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) return i;
	}
	return -1;
}

int find_dulicate_num_BS(vector<int> &nums) {
	int n = nums.size(), low = 0, high = n - 1, mid;
	while (low < high) {
		mid = low + ((high - low) >> 1);
		int count = 0;
		for (int n : nums) {
			if (n >= low && n <= mid) count++;
		}
		cout << low  << " " << mid << " " << high << " " << count << endl;
		// 注意这里是BS的坑！
		if (count <= ((high - low) >> 1) + 1) low = mid + 1;
		else high = mid;
	}
	return low;
}


