class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<set<int>> graph(numCourses, set<int>());
        for (auto p : prerequisites) graph[p.first].insert(p.second);
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (graph[i].size() == 0) q.push(i); 
        }
        vector<int> res;
        queue<int> next;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for (int i = 0; i < numCourses; i++) {
                if (graph[i].find(cur) != graph[i].end()) {
                    graph[i].erase(cur);
                    if (graph[i].size() == 0) next.push(i);
                }
            }
            if (q.empty()) swap(q, next);
        }
        return res.size() == numCourses ? res : vector<int> (0);
    }
};