class Solution {
private:
    int m[1 << 20] = {};
    bool dfs(int M, int T, int k) {
        if (T <= 0 || m[k]) {
            return T > 0 && m[k] > 0;
        }
        for (int i = 0; i < M; i++) {
            if (!(k & 1 << i) && !dfs(M, T - i - 1, k | 1 << i)) {
                return m[k] = 1;
            }
        }
        return !(m[k] = -1);
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int M = maxChoosableInteger, T = desiredTotal;
        int sum = (M + 1) * M / 2;
        return T < 2 ? true : sum < T ? false : sum == T ? M % 2 : dfs(M, T, 0);
    }
};