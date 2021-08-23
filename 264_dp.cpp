class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int p2=1, p3=1,p5=1;
        for (int i = 2; i<= n; i++) {
            int t2 = dp[p2] * 2, t3 = dp[p3] * 3, t5 = dp[p5] * 5;
            int t = min(min(t2, t3), t5);
            dp[i] = t;
            if (t2 == t) {
                p2++;
            }
            if (t3 == t) {
                p3++;
            }
            if (t5 == t) {
                p5++;
            }
        }
        return dp[n];
    }
};
