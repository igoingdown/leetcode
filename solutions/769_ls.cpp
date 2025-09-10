class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, end = 0;
        for (int i = 0; i < arr.size(); i++) {
            end = max(end, arr[i]);
            if (i >= end) res += 1;
        }
        return res;
    }
};
