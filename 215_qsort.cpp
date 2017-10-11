class Solution {
private:
    int partition(vector<int>& s, int l, int r) {
        int i = l + 1, j = r, x = s[l];
        while (i <= j) {
            if (s[i] < x && s[j] > x) {
                swap(s[i++], s[j--]);
            }
            if (s[i] >= x) {
                i++;
            }
            if (s[j] <= x) {
                j--;
            }
        }
        swap(s[l], s[j]);
        return j;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (1) {
            int pos = partition(nums, l, r);
            if (pos == k - 1) {
                return nums[pos];
            }
            if (pos < k -1) {
                l = pos + 1;
            } else {
                r = pos - 1;
            }
        }
    }
};