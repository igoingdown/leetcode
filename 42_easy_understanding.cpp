class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int n = height.size(), res = 0, i = 0;
        for (int i = 0; i < n; i++) {
            if (s.empty() || height[i] <= height[s.top()]) s.push(i);
            else {
                while (!s.empty() && height[i] > height[s.top()]) {
                    int bottom = height[s.top()]; s.pop();
                    res += s.empty() ? 0 : (min(height[s.top()], height[i]) - bottom) * (i - s.top() - 1);
                }
                s.push(i);
            }
        }
        return res;
    }
};