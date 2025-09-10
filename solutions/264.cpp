class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, 1);
        vector<int> index(3, 0);
        vector<int> elem = {2, 3, 5};
        vector<int> val(3, 1);
        for (int i = 1; i < n; i++) {
            int next = INT_MAX;
            for (int j = 0; j < 3; j++) {
                if (res[i-1] >= val[j]) {
                    val[j] = res[index[j]++] * elem[j];
                }
                next = min(next, val[j]);
            }
            res[i] = next;
        }
        return res.back();
    }
};
