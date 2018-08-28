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
    vector<vector<int>> b = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    gameOfLife(b);
    for (auto vec : b) {
        for (auto n : vec)
            cout << n << endl;
        cout << "\n" << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}

void gameOfLife(vector<vector<int>>& board) {
    vector<int> ms = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> ns = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            // 主循环遍历board中所有cell
            // 接下来处理每个cell， 将每个cell的状态由一位（0，1）变成两位（00，01，11， 10）
            //  低位表示本轮的状态，高位表示下一轮的状态，由于初始化时下一轮的状态都是0，只需要关注下一轮状态时1的cell。
            // 遍历每个cell的周围的邻居，计算live和dead的邻居数目。
            int live = 0;
            for (int k = 0; k < 8; k++) {
                if (i + ms[k] >= 0 && i + ms[k] < board.size() && j + ns[k] >= 0 && j + ns[k] < board[i].size()) {
                    live += (board[i + ms[k]] [j + ns[k]] & 1);
                }
            }
            if ((! board[i][j]) && live == 3) {
                board[i][j] = 2;
            } else if (board[i][j] && (live == 2 || live == 3)) {
                board[i][j] = 3;
            }
        }
    }
    // 通过右移一位将本轮状态消除，将下一轮的状态视为本轮的状态，并将下下一轮的状态设为0
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            board[i][j] >>= 1;
        }
    }
}
