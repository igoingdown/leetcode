#include <iostream>
#include <vector>

using namespace std;

int merge_sort(vector<int> &arr, int l, int r);
int merge(vector<int> &arr, int low, int mid, int high);
int inverse_num(vector<int> &arr);

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> v = {7, 5, 6, 4};
	cout << inverse_num(v) << endl;
	return 0;
}

int inverse_num(vector<int> &arr) {
	int l = arr.size(); 
	if (l == 0) return 0;
	return merge_sort(arr, 0, l - 1);
}



int merge_sort(vector<int> &arr, int l, int r) {
	int res = 0;
	if (l < r) {
		int mid = l + ((r - l) >> 1);
		res += merge_sort(arr, l, mid);
		res += merge_sort(arr, mid + 1, r);
		res += merge(arr, l, mid, r);
	}
	return res;
}

int merge(vector<int> &arr, int low, int mid, int high) {
	int ll = low, lr = mid, rl = mid + 1, rr = high, count = 0;
	vector<int> tmp;
	while (ll <= lr && rl <= rr) {
		if (arr[ll] <= arr[rl]) tmp.push_back(arr[ll++]);
		else {
			tmp.push_back(arr[rl++]); count += (lr - ll + 1);
		}
	}
	while (ll <= lr) tmp.push_back(arr[ll++]);
	while (rl <= rr) tmp.push_back(arr[rl++]);
	for (int i = 0; i < tmp.size(); i++) arr[low + i] = tmp[i];
	return count;
}