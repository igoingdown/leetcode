class Comparison {
public:
    bool operator() (const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> v(26, 0);
        for (char c : S) v[c - 'a']++;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comparison> q;
        for (int i = 0; i < 26; i++) {
            if (v[i] > 0) q.push({'a' + i, v[i]});
        }
        string res = "";
        vector<pair<char, int>> tmp;
        while (!q.empty()) {
            while (!q.empty()) {
                tmp.push_back(q.top());
                q.pop();
                if (res == "" || res.back() != tmp.back().first) {
                    res += tmp.back().first;
                    tmp.back().second--;
                    if (tmp.back().second == 0) tmp.pop_back();
                    for (auto p : tmp) q.push(p);
                    tmp.resize(0);
                    break;
                }
            }
        }
        return res.size() == S.size() ? res : "";
    }
};
