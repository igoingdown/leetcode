class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), visit;
        queue<string> q, next;
        map<string, set<string>> word2forward;
        vector<vector<string>> res;
        list<string> path;
        bool found = false;
        q.push(beginWord);
        while (!q.empty()) {
            while (!q.empty()) {
                string cur = q.front(); q.pop(); 
                for (int i = 0; i < cur.size(); i++) {
                    for (int j = 0; j < 26; j++) {
                        if ('a' + j != cur[i]) {
                            string tmp(cur); tmp[i] = 'a' + j;
                            if (tmp == endWord) found = true;
                            if (dict.find(tmp) != dict.end()) {
                                visit.insert(tmp);
                                word2forward[tmp].insert(cur);
                                next.push(tmp);
                            }
                        }
                    }
                }
            }
            if (found) break;
            for (string s : visit) dict.erase(s);
            swap(q, next); visit.clear();
        }
        dfs(res, path, beginWord, endWord, word2forward);
        return res;
    }
    
    void dfs(vector<vector<string>> &res, list<string> &path, string begin, string end, map<string, set<string>> &word2forward) {
        path.push_front(end);
        if (end != begin) {
            for (string s : word2forward[end]) dfs(res, path, begin, s, word2forward);
        } else res.push_back(vector<string>(path.begin(), path.end()));
        path.pop_front();
    }
};