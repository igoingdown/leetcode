class Solution {
private:
    bool dfs(vector<int>& nums, int start, vector<int>& edges, int limit) {
        if (start == nums.size()) {
            if (edges[0] == limit && edges[1] == limit && edges[2] == limit) {
                return true;
            } else {
                return false;
            }
        }
        for (int k = 0; k < 4; k++) {
            if (edges[k] + nums[start] > limit) continue;
            edges[k] += nums[start];
            if (dfs(nums, start + 1, edges, limit)) {
                return true;
            }
            edges[k] -= nums[start];
        }
        return false;
    }
            
public:
    static bool myCompare(int a, int b) {
        return a > b;
    }
    
    bool makesquare(vector<int>& nums) {
        int edge_len = 0, cir = 0;
        for (int n : nums) {
            cir += n;
        }
        if (!cir || cir % 4 != 0) {
            return false;
        }
        sort(nums.begin(), nums.end(), myCompare);
        // sort非常重要，sort之后运行时间缩减了近20倍。
        edge_len = cir / 4;
        vector<int> edges(4, 0);
        return dfs(nums, 0, edges, edge_len);
    }
};