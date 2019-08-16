#include <iostream>
#include <vector>

using namespace std;

bool find_target(vector<vector<int>> &matrix, int target) ;

int main() {
	vector<vector<int>> matrix = {{1, 1, 2}, {3, 4, 5}};
	cout << (find_target(matrix, 6)) << endl;
	return 0;
}


bool find_target(vector<vector<int>> &matrix, int target) {
	int m = matrix.size(), n;
	if (m == 0) return false;
	n = matrix[0].size();
	if (n == 0) return false;
	int low = 0, high = m * n - 1, mid;
	while (low < high) {
		mid = low + ((high - low) >> 1);
		if (matrix[mid / n][mid % n] < target) low = mid + 1;
		else high = mid;
	}
	return matrix[low / n][low % n] == target;
}


// 非完全排序，矩阵无法降维，暴力方法可以对每一行进行BS，O(MlogN)。
// 这里使用高效解法是BS的变形，所选的哨兵为角上的元素，每次将范围缩减一行或一列，O(MAX(M,N))。
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n;
    if (m == 0) return false;
    n = matrix[0].size();
    if (n == 0) return false;
    int row = 0, col = n - 1;
    while (row < m && col >= 0) {
        int cur = matrix[row][col];
        if (cur == target) return true;
        else if (cur > target) col--;
        else row++;
    }
    return false;
}