class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>> q, next;
        set<vector<vector<int>>> s;
        vector<vector<int>> res = {{1,2,3}, {4,5,0}};
        q.push(board); s.insert(board);
        int layer = 0;
        int bias[5] = {1, 0, -1, 0, 1};
        while (!q.empty()) {
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                if (cur == res) return layer;
                pair<int, int> pos = {0, 0};
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (cur[i][j] == 0) {
                            pos.first = i; pos.second = j;
                            break;
                        }
                    }
                }
                for (int i = 0; i < 4; i++) {
                    int x = pos.first + bias[i], y = pos.second + bias[i + 1];
                    if (x >= 0 && x < 2 && y >= 0 && y < 3) {
                        swap(cur[pos.first][pos.second], cur[x][y]);
                        if (s.find(cur) == s.end()) {
                            s.insert(cur); next.push(cur);
                        }
                        swap(cur[pos.first][pos.second], cur[x][y]);
                    }
                }
            }
            swap(q, next);
            layer++;
        }
        return -1;
    }
};