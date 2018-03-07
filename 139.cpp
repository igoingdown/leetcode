class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int ss = s.size(); 
        unordered_set<string> dict; 
        for (string word : wordDict) dict.insert(word);
        vector<bool> dp(ss + 1, false);
        dp[0] = true;
        for (int j = 1; j <= ss; j++) {
            for (int i = j - 1; i >= 0; i--) {
                dp[j] = dp[i] && dict.find(s.substr(i, j - i)) != dict.end();
                if (dp[j]) break;
            }
        }
        return dp[ss];
    }
};