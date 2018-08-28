class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_elem = INT_MAX, sum = 0, n = nums.size();
        if (n == 0) return 0;
        for (int num : nums) {
            min_elem = min(min_elem, num);
            sum += num;
        }
        return sum - min_elem * n;
    }
};