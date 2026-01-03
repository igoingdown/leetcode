class Comparator {
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> q;
        for (int i = 1; i <= m; i++) {
            q.push({i, i});
        }
        for (int i = 1; i < k; i++) {
            auto p = q.top();
            q.pop();
            int next = p.first + p.second;
            if (next <= p.second * n) {
                q.push({next, p.second});
            }
        }
        return q.top().first;
    }
};

