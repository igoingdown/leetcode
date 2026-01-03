class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> a;
        for (int t = N; t; t /= 10) a.push_back(t % 10);
        int l = a.size(), res = 0, pre = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 9; j >= pre; j--) {
                int cur = res;
                for (int k = i; k < l; k++) {
                    cur = cur * 10 + j;
                }
                if (cur <= N) {
                    res = res * 10 + j;
                    pre = j;
                    break;
                }
            }
        }
        return res;
    }
};