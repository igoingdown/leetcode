class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> cur, next;
        cur.push(s);
        unordered_set<string> res;
        unordered_set<string> visited;
        visited.insert(s);
        while(!cur.empty()) {
            while (!cur.empty()) {
                string node = cur.front(); cur.pop();
                if (isValid(node)) {
                    res.insert(node);
                    continue;
                }

                for (int i = 0; i < node.size(); i++) {
                    if (node[i] == '(' || node[i] == ')') {
                        string tmp = node;
                        tmp.erase(i, 1);
                        if (visited.find(tmp) != visited.end()) {
                            continue;
                        }
                        next.push(tmp);
                        visited.insert(tmp);
                    }
                }
            }
            if (res.size() > 0) {
                break;
            }
            swap(cur, next);
        }
        return vector<string>(res.begin(), res.end());
    }

    bool isValid(string& s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') {
                ++cnt;
            }
            if (c == ')') {
                --cnt;
            }
            if (cnt < 0) {
                return false;
            }
        }
        return cnt == 0;
    }
};

