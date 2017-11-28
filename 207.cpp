class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, set<int>> m;
        for (int i = 0; i <  numCourses; i++) {
            m[i] = set<int>();
        }
        for (auto p : prerequisites) {
            m[p.first].insert(p.second);
        }
        queue<int> q;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second.size() == 0) {
                q.push(iter->first);
                numCourses--;
            }
        }
        while (!q.empty() && numCourses > 0) {
            int cur = q.front();
            q.pop();
            for (auto iter = m.begin(); iter != m.end(); iter++) {
                if (iter->second.find(cur) != iter->second.end()) {
                    iter->second.erase(cur);
                    if (iter->second.size() == 0) {
                        q.push(iter->first);
                        numCourses--;
                    }
                }
            }
        }
        return numCourses == 0;
    }
};