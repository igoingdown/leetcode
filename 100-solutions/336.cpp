class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        vector<vector<int> > res;
        for (int i = 0; i < words.size(); i++) {
            string k = words[i];
            reverse(k.begin(), k.end());
            m[k] = i;
        }
        if (m.find("") != m.end()) {
            for (int i = 0; i < words.size(); i++) {
                if (words[i] == "") {
                    continue;
                }
                if (isPalindrome(words[i])) {
                    res.push_back({m[""], i});
                }
            }
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);
                if (m.find(left) != m.end() && isPalindrome(right) && m[left] != i) {
                    res.push_back({i, m[left]});
                }
                if (m.find(right) != m.end() && isPalindrome(left) && m[right] != i) {
                    res.push_back({m[right], i});
                }
            }
        }
        return res;
    }
    
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
