//
//  main.cpp
//  54
//
//  Created by 赵明星 on 2017/2/26.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}};
    vector<int> res = spiralOrder(matrix);
    for (auto n: res) {
        cout << n << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) {
        return vector<int> (0);
    }
    if (matrix[0].size() == 0) {
        return vector<int> (0);
    }
    int m = matrix.size(), n = matrix[0].size();
    int s = m * n;
    vector<int> res(s, 0);
    int i = 0, j = 0;
    for (int k = 0; k < s;) {
        int l = j;
        while (l <= n - j - 1) {
            res[k++] = matrix[i][l++];
        }
        l = i + 1;
        while (l <= m - i - 1) {
            res[k++] = matrix[l++][n - j - 1];
        }
        l = n - j - 2;
        while (l >= j && i != m - i - 1) {
            res[k++] = matrix[m - i - 1][l--];
        }
        l = m - i - 2;
        while (l > i && j != n - j - 1) {
            res[k++] = matrix[l--][j];
        }
        i++;
        j++;
    }
    return res;
}











