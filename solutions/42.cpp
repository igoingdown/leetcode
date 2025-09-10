class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int n = height.size(), res = 0, i = 0;
        while (i < n) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int bottom = height[s.top()]; s.pop();
                if (!s.empty()) {
                    int top = min(height[s.top()], height[i]), width = i - s.top() - 1;
                    res += (top - bottom) * width;
                }
            }
            s.push(i++);
        }
        return res;
    }
};