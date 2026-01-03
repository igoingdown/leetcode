class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, 1);
        vector<int> val(primes.size(), 1);
        vector<int> idx(primes.size(), 0);
        
        int next = 1;
        for (int i = 0; i < n; i++) {
            ugly[i] = next;
            next = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                if (val[j] == ugly[i]) {
                    val[j] = ugly[idx[j]++] * primes[j];
                }
                next = min(next, val[j]);
            }
        }
        return ugly.back();
    }
};
