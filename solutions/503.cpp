class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        unordered_map<int, int> m;
        stack<int> s;
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                m[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                if (m.find(s.top()) == m.end()) {
                    m[s.top()] = nums[i];
                }
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (m.find(i) == m.end() ? -1 : m[i]); 
        }
        return nums;
    }
};