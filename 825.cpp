class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int res = 0;
        for (int A = 0; A < ages.size(); A++) { // a
            if (ages[A] > 14) {
                auto right = lower_bound(ages.begin(), ages.end(), ages[A] + 1);
                auto left = upper_bound(ages.begin(), ages.end(), ages[A] * 0.5 + 7);
                res += right - left - 1;
            }
        }
        return res;
    }
};