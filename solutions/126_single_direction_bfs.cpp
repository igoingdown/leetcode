class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_map<string, bool> visited;
        for (const string &str : wordList) visited[str] = false;
        queue<vector<string>> q_path, next_path;
        q_path.push({beginWord});
        while (!q_path.empty()) {
            unordered_set<string> layer_visisted;
            while (!q_path.empty()) {
                vector<string> cur_path = q_path.front(); q_path.pop();
                if (cur_path.back() == endWord) res.push_back(cur_path);
                for (int i = 0; i < cur_path.back().size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (cur_path.back()[i] != c) {
                            string tmp(cur_path.back()); tmp[i] = c;
                            if (visited.find(tmp) != visited.end() && !visited[tmp]) {
                                cur_path.push_back(tmp);
                                next_path.push(cur_path);
                                cur_path.pop_back();
                                layer_visisted.insert(tmp);
                            }
                        }
                    }
                }
            }
            if (!res.empty()) return res;
            swap(q_path, next_path);
            for (string word : layer_visisted) visited[word] = true;
        }
        return res;
    }
};