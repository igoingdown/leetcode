class Solution {
public:
    string makeLargestSpecial(string S) {
        string res = S;
    queue<string> q;
    q.push(S);
    set<string> visited, next;
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        visited.insert(s);
        vector<int> dp(s.size() + 1);
        for (int i = 0; i < s.size(); i++) dp[i + 1] = dp[i] + (s[i] == '0' ? -1 : 1);
        // s(i-1, j] and s(j + 1, k - 1] are special binary string and not equal, swap them and push the new res to q.
        for (int i = 0; i < s.size(); i++) {
            int j = i + 1;
            while (j < s.size()) {
                while (j < s.size() && dp[j] - dp[i] > 0) j++;
                if (j < s.size() && dp[j] - dp[i] == 0) {
                    int k = j + 1;
                    while (k <= s.size()) {
                        while (k <= s.size() && dp[k] - dp[j] > 0) k++;
                        if (k <= s.size() && dp[k] - dp[j] == 0) {
                            if (s.substr(i, j - i) != s.substr(j, k - j)) {
                                string candidate = s.substr(0, i) + s.substr(j, k - j) + s.substr(i, j - i) + (k < s.size() ? s.substr(k) : "");
                                if (visited.find(candidate) == visited.end()) next.insert(candidate);
                            }
                            k++;
                        } else break;
                    }
                    j++;
                } else break;
            }
        }
        for (auto iter = next.begin(); iter != next.end(); iter++) {
            q.push(*iter);
            res = max(res, *iter);
        }
        next.clear();
    }
    return res;
    }
};