class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur(1, poured);
        while(query_row--) {
            vector<double> next(cur.size() + 1);
            for(int i = 0; i < cur.size(); i++) {
                double overflow = max(cur[i] - 1.0, 0.0) / 2.0;
                next[i] += overflow;
                next[i + 1] += overflow;
            }
            swap(cur, next);
        }
        return cur[query_glass] > 1 ? 1 : cur[query_glass];
    }
};
