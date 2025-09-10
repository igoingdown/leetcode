class Solution {
private:
    vector<int> pow;
    int getKey(vector<int> nums) {
        int s = nums.size();
        int res = 0;
        for (int i = s - 1, p = 1; i >= 0; i--, p *= 10) {
            res += nums[i] * p;
        }
        return res;
    }
    
    int dfs(const vector<int>& price, vector<vector<int>>& special, unordered_map<int, int>& m, int k) {
        if (m.count(k)) {
            return m[k];
        }
        int ans = 0, n = price.size();
        for (int i = 0; i < n; i++) {
            ans += price[i] * ((k / pow[i]) % 10);
        }
        
        for (auto sp : special) {
            int key = 0, i = 0, t = 0;
            while (i < n) {
                int itemC = (k / pow[i]) % 10;
                if (sp[i] <= itemC) {
                    key += pow[i] * (itemC - sp[i++]);
                } else {
                    break;
                }
            }
            if (i == n) {
                ans = min(ans, sp[n] + dfs(price, special, m, key));
            }
        }
        return m[k] = ans;
    }
    
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int s = needs.size();
        if (s < 1) {
            return 0;
        }
        pow.clear();
        pow.resize(s, 1);
        for (int i = s - 2; i >= 0; i--) {
            pow[i] = pow[i + 1] * 10;
        }
        unordered_map<int, int> m;
        int key = getKey(needs);
        return dfs(price, special, m, key);
    }
    
    
};