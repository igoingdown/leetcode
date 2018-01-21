class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int l = arr.size();
        if (l < 2) return l;
        return dfs(arr, 0, l - 1);
    }
    int dfs(vector<int>& arr, int b, int e) {
        if (b == e) return 1;
        if (b > e) return 0;
        int max_res = 1;
        for (int i = b; i < e; i++) {
            int max_left = INT_MIN, min_right = INT_MAX;
            for (int j = b; j <= i; j++) max_left = max(max_left, arr[j]);
            if (max_left == i) max_res = max(max_res, dfs(arr, b, i) + dfs(arr, i + 1, e));
        }
        return max_res;
    }
};
