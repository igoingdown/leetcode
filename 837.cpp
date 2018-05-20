class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (N < K) return 0;
        if (K + W < N) return 1;
        vector<double> dp(20005), pre(20005);
        dp[0] = 1.0, pre[1] = 1.0;
        for(int i = 1; i < K + W; i++) {
            int b = max(0, i - W), e = min(i - 1, K - 1);
            dp[i] = (pre[e + 1] - pre[b]) / W;
            pre[i + 1] = pre[i] + dp[i];
        }
        double res = 0.0;
        for (int i = K; i <= N; i++) res += dp[i];
        return res;
    }
};
