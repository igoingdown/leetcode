class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        int l = (s1 + s2 + 1) >> 1, r = (s1 + s2 + 2) >> 1;
        return (getKth(nums1, 0, s1, nums2, 0, s2, l) + getKth(nums1, 0, s1, nums2, 0, s2, r)) / 2.0;
    }
    int getKth(vector<int>& l, int ls, int le, vector<int>& s, int ss, int se, int k) {
        if (le - ls < se - ss) return getKth(s, ss, se, l, ls, le, k);
        if (se == ss) return l[ls + k - 1];
        if (k == 1) return min(l[ls], s[ss]);
        int i = min(ls + k / 2, le), j = min(ss + k / 2, se);
        if (l[i - 1] > s[j - 1]) return getKth(l, ls, le, s, j, se, k + ss - j);
        else return getKth(l, i, le, s, ss, se, k + ls - i);
        return 0;
    }
};