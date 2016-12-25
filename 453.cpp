class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int sum = 0, min_n = nums[0];
        for (auto n: nums)
        {
            sum += n;
            if(n < min_n)
                min_n = n;
        }
        return sum - min_n * nums.size();
    }
};
