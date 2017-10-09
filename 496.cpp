class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> m; // mapping from element to its next greater element.
        stack<int> s; // save a decreasing array, when there is a bigger num, 
                      // pop smaller ones whose next greater num is the bigger num. 
                      // and push the bigger num to the top of the stack.
        for (int n : nums) {
            while (!s.empty() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> res;
        for (int n : findNums) {
            res.push_back(m.find(n) == m.end() ? -1 : m[n]);
        }
        return res;
    }
};