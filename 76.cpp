class Solution {
public:
    string minWindow(string s, string t) {
        int count = t.size(), min_start = 0, min_len = INT_MAX;
        bool include = false;
        vector<int> tMap(256), aMap(256);
        for (char c : t) tMap[c]++;
        for (int i = 0, j = 0; j < s.size(); j++) {
            aMap[s[j]]++;
            if (count > 0 && tMap[s[j]] >= aMap[s[j]]) count--;
            if (count == 0) include = true;
            if (include) {
                while (i <= j) {
                    if (min_len > j - i + 1) {
                        min_len = j - i + 1; min_start = i;
                    }
                    if (tMap[s[i]] > 0 && aMap[s[i]] == tMap[s[i]]) break;
                    else {
                        aMap[s[i]]--; i++;
                    }
                }
            }
        }
        return include ? s.substr(min_start, min_len) : ""; 
    }
};