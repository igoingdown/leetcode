class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int l = temperatures.size(), i = 0;
        vector<int> res(l);
        stack<int> s;
        while (i < l) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                int cur = s.top();
                s.pop();
                res[cur] = i - cur;
            }
            s.push(i++);
        }
        return res;
    }
};