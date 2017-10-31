class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> m;
        for (string s : wordList) m[s] = 0;
        queue<string> q;
        q.push(beginWord);
        int dis = 1, last_level = 1;
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            last_level--;
            for (int i = 0; i < current.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == current[i]) continue;
                    char tmp = current[i];
                    current[i] = c;
                    if (m.find(current) != m.end() && m[current] == 0) {
                        if (current == endWord) return dis + 1;
                        m[current] = 1;
                        q.push(current);
                    }
                    current[i] = tmp;
                }
            }
            if (last_level == 0) {
                last_level = q.size();
                dis++;
            }
        }
        return 0;
    }
};