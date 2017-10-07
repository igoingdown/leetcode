class Solution {
private:
    int getKey(vector<int> nums, vector<int> pow) {
        int s = nums.size();
        int res = 0;
        for (int i = 0; i < s; i++) {
            res += nums[i] * pow[i];
        }
        return res;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int s = needs.size();
        if (s < 1) {
            return 0;
        }
        vector<int> pow(s, 1);
        for (int i = s - 2; i >= 0; i--) {
            pow[i] = 10 * pow[i + 1];
        }
        int dimension = 0;
        for (int i = s -1; i >= 0; i--) {
            dimension += pow[i] * needs[i];
        }
        vector<int> tmp(s, 0);
        vector<int> dp(dimension, 0);
        for (int i = 1; i < dimension; i++) {
            int t = i;
            tmp.clear();
            tmp.resize(s, 0);
            for (int j = 0; j < s; j++) {
                if (t / pow[j] > 6) {
                    break;
                } {
                    tmp[j] = t / pow[j];
                    dp[i] += price[j] * tmp[j];
                    t %= pow[j];
                }
            }
        }
        for (int i = 1; i < dimension; i++) {
            tmp.clear();
            tmp.resize(s, 0);
            int t = i;
            bool tooBig = false;
            for (int j = 0; j < s; j++) {
                if (t / pow[j] > 6) {
                    tooBig = true;
                    break;
                } {
                    tmp[j] = t / pow[j];
                    t %= pow[j];
                }
            }
            if (!tooBig) {
                for (auto sp : special) {
                    bool offerRecv = true;
                    for (int j = 0; j < s; j++) {
                        if (sp[j] > tmp[j]) {
                            offerRecv = false;
                            break;
                        }
                    }
                    if (offerRecv) {
                        for (int l = 0; l < s; l++) {
                            tmp[l] -= sp[l];
                        }
                        dp[i] = min(dp[i], dp[getKey(tmp, pow)] + sp[s]);
                    }
                }
            }
        }
        return dp[getKey(needs, pow)];
    }
};