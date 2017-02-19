//
//  main.cpp
//  74
//
//  Created by 赵明星 on 2017/2/19.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix = {{1}, {3}};
    if (searchMatrix(matrix, 1)) {
        cout << "found!!" << endl;
    } else {
        cout << "not found!!" << endl;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0) {
        return false;
    }
    if (matrix[0].size() == 0) {
        return false;
    }
    if (target > matrix[matrix.size() - 1][matrix[0].size() - 1] || target < matrix[0][0]) {
        return false;
    }
    int rowLow = 0, rowHigh = matrix.size() - 1;
    while (rowLow < rowHigh) {
        int rowMid = rowLow + (rowHigh - rowLow) / 2;
        if (matrix[rowMid][0] == target) {
            return true;
        } else if (matrix[rowMid][0] > target) {
            rowHigh = rowMid - 1;
        } else if(matrix[rowMid][matrix[0].size() - 1] < target) {
            rowLow = rowMid + 1;
        } else {
            rowHigh = rowMid;
            break;
        }
    }
    if (matrix[rowHigh][matrix[0].size() - 1] < target) {
        return false;
    }
    int columnLow = 0, columnHigh = matrix[0].size() - 1;
    while (columnLow < columnHigh) {
        int columnMid = columnLow + (columnHigh - columnLow) / 2;
        if (matrix[rowHigh][columnMid] < target) {
            columnLow = columnMid + 1;
        } else {
            columnHigh = columnMid;
        }
    }
    return matrix[rowHigh][columnLow] == target ? true : false;
}








