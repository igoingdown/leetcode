class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s = citations.size();
        int low = 0, high = s -1, mid;
        while (low <= high) {
            mid = low + ((high - low) >> 2);
            if (citations[mid] == s - mid) {
                return citations[mid];
            } else if (citations[mid] > s - mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return s - high - 1;
    }
};
