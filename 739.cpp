class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int l = temperatures.size(), i = 0;
        vector<int> res(l);
        stack<int> s;
        while (i < l) {
            if (s.empty() || temperatures[s.top()] >= temperatures[i]) {
                s.push(i++);
            } else {
                int cur = s.top();
                s.pop();
                res[cur] = i - cur;
            }
        }
        return res;
    }
};