class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> visit;
        for (string word : wordList) visit[word] = false;
        queue<string> q, next;
        q.push(beginWord);
        int dis = 1;
        while (!q.empty()) {
            while (!q.empty()) {
                string cur = q.front();
                q.pop();
                if (cur == endWord) return dis;
                for (int i = 0; i < cur.size(); i++) {
                    char tmp = cur[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == tmp) continue;
                        cur[i] = c;
                        if (visit.find(cur) != visit.end() && !visit[cur]) {
                            next.push(cur);
                            visit[cur] = true;
                        }
                        cur[i] = tmp;
                    }
                }
            }
            swap(q, next);
            dis++;
        }
        return 0;
    }
};