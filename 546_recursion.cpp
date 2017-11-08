#include <iostream>
#include <vector>
#include <map>

using namespace std;

 map<pair<int, int>, int> m;
int removeBoxes(vector<int>& boxes, int i, int j, int k, vector<vector<vector<int>>>& tmp);
int removeBoxes(vector<int>& boxes);


int main(int argc, char const *argv[])
{
	/* code */
	int a[9] = {1,3,2,2,2,3,4,3,1};
	vector<int> v(a, a + 9);
	for (int n : v) {
		cout << n << endl;
	}
	cout << removeBoxes(v) << endl;
	return 0;
}



int removeBoxes(vector<int>& boxes, int i, int j, int k, vector<vector<vector<int>>>& tmp) {
    if (i > j) return 0;
    if (tmp[i][j][k] > 0) return tmp[i][j][k];
    int res = (k + 1) * (k + 1) + removeBoxes(boxes, i + 1, j, 0, tmp);
    for (int m = i + 1; m <= j; m++) {
        if (boxes[m] == boxes[i]) {
            res = max(res, removeBoxes(boxes, i + 1, m - 1, 0, tmp) + removeBoxes(boxes, m, j, k + 1, tmp));
        }
    }
    return tmp[i][j][k] = res;
}

int removeBoxes(vector<int>& boxes) {
    int n = boxes.size();
    if (n < 2) return n;
    vector<vector<vector<int>>> tmp(n, vector<vector<int>>(n, vector<int>(n, 0)));
    return removeBoxes(boxes, 0, n - 1, 0, tmp);
}
