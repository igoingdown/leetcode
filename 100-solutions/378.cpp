#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthSmallest(vector<vector<int> >& matrix, int k);



int main(int argc, char const *argv[])
{
	/* code */
	int a[2][2] = { {1, 2}, {15, 20}};
	vector< vector< int > > v;
	vector<int> t(a[0], a[0]+2);
	v.push_back(t);
	vector<int> t1(a[1], a[1]+2);
	v.push_back(t1);
	cout << kthSmallest(v, 2) << endl;
	return 0;
}



int kthSmallest(vector<vector<int> >& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0], high = matrix[n - 1][n -1];
    int mid = 0;
    while (low < high) {

        mid = low + ( (high - low) >> 1 );
        int num = 0;
        for (int i = 0; i < n; i++) {
            num += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        cout << "low: " << low << "\thigh: " << high << "\tnum: " << num << endl;
        if (num < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}