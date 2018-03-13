class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur(1, poured), next(1);
        bool all_zero = false;
        while (query_row-- && !all_zero) {
            all_zero = true;
            next[0] = cur[0] > 1 ? (cur[0] - 1) / 2 : 0; 
            if (next[0] > 0) all_zero = false;
            for (int i = 1; i < next.size(); i++) {
                next[i] = (cur[i - 1] > 1 ? (cur[i - 1] - 1) / 2 : 0) + (cur[i] > 1 ? (cur[i] - 1) / 2 : 0);
                if (next[i] > 0) all_zero = false;
            }
            next.push_back(cur[next.size() - 1] > 1 ? (cur[next.size() - 1] - 1) / 2 : 0);
            if (next.back() > 0) all_zero = false;
            cur = next;
        }
        if (query_row > 0 && all_zero || query_glass >= cur.size()) return 0;
        return  cur[query_glass] >= 1 ? 1 : cur[query_glass];
    }
};