class Solution {
private:
    int dfs(unordered_map<string, int>& dp, const vector<vector<int>>& mp, string target) {
        if (dp.count(target)) {
            return dp[target];
        }
        vector<int> tar(26, 0);
        for (char c : target) {
            tar[c - 'a']++;
        }
        // apply every sticker and get the minimus ans as res;
        int ans = INT_MAX;
        
        for (auto sticker : mp) {
            string s;
            for (int i = 0; i < 26; i++) {
                if (tar[i]) {
                    s += string(max(0, tar[i] - sticker[i]), 'a' + i);
                }
            }
            if (s.size() < target.size()) {
                int tmp = dfs(dp, mp, s);
                if (tmp != -1) {
                    ans = min(ans, 1 + tmp);
                } 
            }
        }
        return dp[target] = ans == INT_MAX ? -1 : ans;
    }
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = stickers.size();
        vector<vector<int>> mp(m, vector<int> (26, 0));
        for (int i = 0; i < m; i++) {
            for (char c : stickers[i]) {
                mp[i][c - 'a'] ++;
            }
        }
        unordered_map<string, int> dp;
        dp[""] = 0;
        return dfs(dp, mp, target);
    }
};