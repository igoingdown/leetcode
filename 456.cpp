class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN, n = nums.size();
        stack<int> s;
        for (int i = n - 1; i>= 0; i--) {
            if (nums[i] < s3) {
                return true;
            } 
            while (!s.empty() && s.top() < nums[i]) {
                s3 = s.top();
                s.pop();
            }
            s.push(nums[i]);
            
        }
        return false;
    }
};