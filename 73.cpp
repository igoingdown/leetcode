//
//  main.cpp
//  73
//
//  Created by 赵明星 on 2017/2/19.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix = {{0, 0, 0, 5}, {4, 3, 1, 4}, {0, 1, 1, 4}, {1, 2, 1, 3}, {0, 0, 1, 1}};
    setZeroes(matrix);
    for (auto row: matrix) {
        cout << "[ ";
        for (auto n: row) {
            cout << n << " ";
        }
        cout << " ]" << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}

void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;
        int col = 1;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) col = 0;
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j > 0; j--) {
                if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }
            if (col == 0) matrix[i][0] = 0;
        }
    }







