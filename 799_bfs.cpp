class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur;
        cur.push_back(double(poured));
        for (int i = 0; i<query_row; i++) {
            vector<double> next(cur.size() + 1, 0);
            for (int j = 0; j < cur.size(); j++) {
                if (cur[j] > 1) {
                    next[j] += ((cur[j] - 1) / 2);
                    next[j+1] += ((cur[j] - 1) / 2);
                }
            }
            swap(cur, next);
        }
        if (cur[query_glass] > 1) {
            cur[query_glass] = 1;
        }
        return cur[query_glass];
    }
};
