//
//  main.cpp
//  289
//
//  Created by 赵明星 on 2016/12/6.
//  Copyright © 2016年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void gameOfLife(vector<vector<int>>& board);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> b = {{1, 1}, {1, 0}};
    gameOfLife(b);
    for (auto vec : b) {
        for (auto n : vec)
            cout << n << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}

void gameOfLife(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            // 主循环遍历board中所有cell
            // 接下来处理每个cell， 将每个cell的状态由一位（0，1）变成两位（00，01，11， 10）
            // 遍历每个cell的周围的邻居，计算live和dead的邻居数目。
            int live = 0, dead = 0, all = 0;
            for (int m = -1; m < 2; m++) {
                for (int n = -1; n < 2; n++) {
                    // 除去该cell自身
                    if (! (m == 0 && n == 0)) {
                        // 仅保留未越界元素
                        if (i + m >= 0 && i + m < board.size() && j + n >= 0 && j + n < board[i].size()) {
                            live += (board[i + m] [j + n] & 1);
                            all ++;
                        }
                    }
                }
            }
            dead = all - live;
            cout << dead << "\t" << live << endl;
            if ((! board[i][j]) && live == 3) {
                board[i][j] = 2;
            } else if (board[i][j] && live < 2) {
                board[i][j] = 1;
            } else if (board[i][j] && live > 3) {
                board[i][j] = 1;
            } else if (board[i][j] && (live == 2 || live == 3)) {
                board[i][j] = 3;
            }
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            board[i][j] = board[i][j] & 2;
            board[i][j] /= 2;
        }
    }
}
