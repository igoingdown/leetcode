#include <iostream>
#include <vector>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x);


int main(void) {
	int a[5] = {1,2,3,4,5};
	vector<int> v(a, a+5 );
	vector<int> res = findClosestElements(v, 4, -1);
	for (auto i = res.begin(); i != res.end(); i++) {
		cout << *i << endl;
	}
	return 0;
}




vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int low = index - 1, high = index;
    while(k--) {
        (low == -1 || (high < arr.size() &&  abs(arr[high] - x) < abs(x - arr[low]))) ? high++ : low--;
    }
    return vector<int> (arr.begin() + low + 1, arr.begin() + high);
}




