class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q, next;
        map<string, int> dis;
        for (string e : deadends) dis[e] = -1;
        if (dis["0000"] < 0) return -1;
        q.push("0000"); dis["0000"] = 0;
        int layer = 1;
        while (!q.empty()) {
            while (!q.empty()) {
                string cur = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    for (int j = -1; j < 2; j += 2) {
                        string tmp(cur);
                        tmp[i] += j;
                        if (tmp[i] > '9') tmp[i] -= 10;
                        if (tmp[i] < '0') tmp[i] += 10;
                        if (tmp == target) return layer;
                        if (dis[tmp] == 0 && tmp != "0000") {
                            next.push(tmp);
                            dis[tmp] = layer;
                        }
                    }
                }
            }
            swap(q, next);
            layer++;
        }
        return target == "000" ? 0 : -1;
    }
};