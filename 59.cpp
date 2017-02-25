//
//  main.cpp
//  59
//
//  Created by 赵明星 on 2017/2/25.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix = generateMatrix(1);
    for (auto v : matrix) {
        for (auto n: v) {
            cout << n << endl;
        }
    }
    std::cout << "Hello, World!\n";
    return 0;
}

vector<vector<int>> generateMatrix(int n) {
    vector< vector<int> > res(n, vector<int>(n));
    int i = 0;
    for (int k = 1; k <= n * n;) {
        int j = i;
        while (j <= n - i - 1) {
            res[i][j++] = k++;
        }
        j = i + 1;
        while (j <= n - i - 1) {
            res[j++][n - i - 1] = k++;
        }
        j = n - i - 2;
        while (j >= i) {
            res[n - i - 1][j--] = k++;
        }
        j = n - i - 2;
        while (j > i) {
            res[j--][i] = k++;
        }
        i++;
    }
    return res;
}












