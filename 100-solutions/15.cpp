class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;    // 存储结果的二维数组
        int n = nums.size();
        if (n < 3) return res;      // 边界情况：数组长度小于3，直接返回空结果
        
        // 1. 排序是算法的关键第一步
        sort(nums.begin(), nums.end());  // O(nlogn)
        
        // 2. 固定第一个数，然后用双指针找剩余两个数
        for (int i = 0; i < n - 2; i++) {  // 注意 n-2：因为后面还需要两个数
            // 关键优化：跳过重复的第一个数，避免重复结果
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // 3. 双指针：left从i+1开始，right从末尾开始
            int l = i + 1, r = n - 1;
            
            // 4. 双指针向中间移动
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum > 0) {
                    r--;    // 和太大，右指针左移
                } else if (sum < 0) {
                    l++;    // 和太小，左指针右移
                } else {
                    // 找到一组解
                    res.push_back({nums[i], nums[l], nums[r]});
                    
                    // 移动双指针
                    l++;
                    r--;
                    
                    // 关键优化：跳过重复的数，跳过已经加入计算的数
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        return res;
    }
};