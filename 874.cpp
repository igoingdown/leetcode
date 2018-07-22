class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> s;
        for (const auto &p : obstacles) s.insert({p[0], p[1]});
        long long curX = 0, curY = 0, cur_dir = 0, res = 0;
        for (int c : commands) {
            if (c == -1) {
                if (cur_dir == 3) cur_dir = 0;
                else cur_dir++;
            } else if (c == -2) {
                if (cur_dir == 0) cur_dir = 3;
                else cur_dir--;
            } else {
                switch (cur_dir) {
                    case 0: // N
                        for (int i = 0; i < c; i++) {
                            if (s.find({curX, curY + 1}) != s.end()) break;
                            curY++;
                        }
                        break;
                    case 1: // E
                        for (int i = 0; i < c; i++) {
                            if (s.find({curX + 1, curY}) != s.end()) break;
                            curX++;
                        }
                        break;
                    case 2: // S
                        for (int i = 0; i < c; i++) {
                            if (s.find({curX, curY - 1}) != s.end()) break;
                            curY--;
                        }
                        break;
                    case 3: // W
                        for (int i = 0; i < c; i++) {
                            if (s.find({curX - 1, curY}) != s.end()) break;
                            curX--;
                        }
                        break;
                    default:
                        break;
                }
            }
            res = max(res, curX * curX + curY * curY);
        }
        return res;
    }
};