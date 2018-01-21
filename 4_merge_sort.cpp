class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) swap(nums1, nums2);
        int l1 = nums1.size(), l2 = nums2.size();
        if (l1 + l2 == 0) return 0;
        nums1.resize(l1 + l2, 0);
        bool flag = (l1 + l2) % 2;
        int limit = flag ? (l1 + l2) / 2 : (l1 + l2) / 2 - 1;
        for (int i = l1 + l2 - 1; i >= limit; i--) {
            while (l2 > 0 && i >= limit) nums1[i--] = (nums1[l1- 1] > nums2[l2 - 1]) ? nums1[--l1] : nums2[--l2];
        }
        return flag ? nums1[limit] : ((double)nums1[limit] + nums1[limit + 1]) / 2;
    }
};