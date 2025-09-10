class Solution {
public:
    string minWindow(string s, string t) {
        int count = t.size(), min_start = 0, min_len = INT_MAX;
        map<char, int> tMap, aMap;
        for (char c : t) tMap[c]++;
        for (int i = 0, j = 0; j < s.size(); j++) {
            aMap[s[j]]++;
            if (count > 0 && tMap.find(s[j]) != tMap.end() && tMap[s[j]] >= aMap[s[j]]) count--;
            if (count == 0) {
                while (i <= j &&(tMap.find(s[i]) == tMap.end() || aMap[s[i]] > tMap[s[i]])) {
                    aMap[s[i]]--; 
                    i++;
                }
                if (min_len > j - i + 1) {
                    min_len = j - i + 1;
                    min_start = i;
                }
            }
        }
        return count == 0 ? s.substr(min_start, min_len) : ""; 
    }
};