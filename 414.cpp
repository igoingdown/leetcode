class Solution {
public:
    int thirdMax(vector<int>& nums) {
        bool flag = false;
        long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
        for (int num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num < max1 && num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num < max2 && num > max3) {
                max3 = num;
                flag = true;
            }
        }
        return max3 == LLONG_MIN ? max1 : max3;
    }
};