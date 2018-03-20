#include <iostream>
#include <vector>

using namespace std;


int robotMove(int threshold, int rows, int cols);;
void dfs(vector<vector<char>> &matrix, int rows, int cols, int row, int col, const vector<int> &bias);

int main() {
	cout << robotMove(0, 10, 1) << endl;
	return 0;
}

int robotMove(int threshold, int rows, int cols) {
	if (rows == 0 || cols == 0) return 0;
	vector<vector<char>> matrix(rows, vector<char>(cols, ' '));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int res = 0, row = i, col = j;
			while (row || col) {
				if (row) {
					res += row % 10; row /= 10;
				}
				if (col) {
					res += col % 10; col /= 10;
				}
			}
			if (res == threshold) matrix[i][j] = 'X';
		}
	}
	for (auto v : matrix) {
		for (char n : v) cout << n << " ";
		cout << endl;
	}
	vector<int> bias = {1, 0, -1, 0, 1};
	dfs(matrix, rows, cols, 0, 0, bias);
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) count += matrix[i][j] == 'O' ? 1 : 0;
	}
	return count;
}

void dfs(vector<vector<char>> &matrix, int rows, int cols, int row, int col, const vector<int> &bias) {
	if (row >= rows || row < 0 || col >= cols || col < 0 || matrix[row][col] != ' ') return;
	matrix[row][col] = 'O';
	for (int i = 0; i < 4; i++) {
		int x = row + bias[i], y = col + bias[i + 1];
		dfs(matrix, rows, cols, x, y, bias);
	}
}