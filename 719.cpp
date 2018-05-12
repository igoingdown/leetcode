class Solution {
public: 
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> dis(1000001);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++)
                dis[nums[i] > nums[j] ? nums[i] - nums[j] : nums[j] - nums[i]]++;
        }
        int i = 0;
        while (i < 1000001 && k > dis[i]) {
            k -= dis[i]; i++;
        }
        return i;
    }
};