class Solution {
public:
    int candy(vector<int>& ratings) {
        map<int, set<int>> g;
        for (int i = 0; i < ratings.size(); i++) {
            g[i] = set<int>();
            if (i > 0 && ratings[i] > ratings[i - 1]) g[i].insert(i - 1);
            if (i + 1 < ratings.size() && ratings[i] > ratings[i + 1]) g[i].insert(i + 1);
        }
        vector<int> q, next;
        int layer = 1, res = 0;
        for (auto iter = g.begin(); iter != g.end(); iter++) {
            if (iter->second.empty()) q.push_back(iter->first);
        }
        while (!q.empty()) {
            next.clear();
            for (int cur : q) g.erase(cur);
            res += layer * q.size();
            for (int cur : q) {
                for (auto iter = g.begin(); iter != g.end(); iter++) {
                    if (iter->second.find(cur) != iter->second.end()) {
                        iter->second.erase(cur);
                        if (iter->second.empty()) next.push_back(iter->first);
                    }
                }
            }
            swap(q, next); layer++;
        }
        return res;
    }
};