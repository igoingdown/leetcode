class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (auto n : nums) {
            auto ptr = lower_bound(res.begin(), res.end(), n);
            if ( ptr == res.end() ) {
                res.push_back(n);
            } else {
                *ptr = n;
            }
        }
        return res.size();
    }
};
