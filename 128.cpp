class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int length = 0;
        for (auto i = s.begin(); i != s.end(); i++) {
            if (s.find(*i - 1) == s.end()) {
                int end = *i + 1;
                while(s.find(end) != s.end()) {
                    end++;
                }
                length = max(length, end - *i);
            }
        }
        return length;
    }
};