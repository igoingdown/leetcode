class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, major = 0;
        for (auto n : nums) {
            if (counter == 0) {
                major = n;
            }
            if (n == major) {
                counter ++;
            } else {
                counter --;
            }
        }
        return major;
    }
};