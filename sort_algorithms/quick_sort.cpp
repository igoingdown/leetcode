#include <iostream>
#include <vector>

using namespace std;

void quick_s(vector<int>& s, int l, int r);
int partition_1(vector<int>& s, int l, int r);
int partition_2(vector<int>& s, int l, int r);
void quick_sort_with_inline_partition(vector<int> & nums, int l, int r);

int main(void) {
	int a[4] = {3, 2, 9, 5};
	vector<int> v(a, a + 4);
	quick_s(v, 0, 3);
	for (auto i : v) cout << i << endl;
	return 0;
}


void quick_s(vector<int>& s, int l, int r) {
	if (l < r) {
		int i = partition_2(s, l, r);
		quick_s(s, l, i - 1);
		quick_s(s, i + 1, r);
	}
}


int partition_1(vector<int>& s, int l, int r) {
	int i = l, j = r, x = s[l];
	while (i < j) {
		while (i < j && s[j] >= x) j--;
		if (i < j) s[i++] = s[j];
		while (i < j && s[i] <= x) i++;
		if (i < j) s[j--] = s[i];
	}
	s[i] = x;
	return i;
}


int partition_2(vector<int>& s, int l, int r) {
	int i = l + 1, j = r, x = s[l];
	while (i <= j) {
		if (s[i] > x && s[j] < x) swap(s[i++], s[j--]);
		if (s[i] <= x) i++; 
		if (s[j] >= x) j--;
	}
	swap(s[l], s[j]);
	return j;
}


void quick_sort_with_inline_partition(vector<int> & nums, int l, int r) {
    swap(nums[l], nums[l + (r - l) / 2]);
    if (l < r) {
        int i = l, j = r, x = nums[l];
        while (i < j) {
            while (i < j && nums[j] >= x) j--;
            if (i < j) nums[i++] = nums[j];
            while (i < j && nums[i] <= x) i++;
            if (i < j) nums[j--] = nums[i];
        }
        nums[i] = x;
        quick_sort(nums, l, i - 1);
        quick_sort(nums, i + 1, r);
    }
}
















