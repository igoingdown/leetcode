class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<int, int>> states;
        for (int i = 0; i < quality.size(); i++) states.push_back({quality[i], wage[i]});
        sort(states.begin(), states.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            return a.second / (double) a.first < b.second / (double) b.first;
        });
        sort(quality.begin(), quality.end());
        priority_queue<int> q;  // construct max heap with vector container and less comparator by default 
        double res = numeric_limits<double>::max();
        int sum = 0;
        for (auto state : states) {
            q.push(state.first);
            sum += state.first;
            if (q.size() > K) {
                sum -= q.top();
                q.pop();
            }
            if (q.size() == K) res = min(res, sum * (state.second / (double) state.first));
        }
        return res;
    }
};