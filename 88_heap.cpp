class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int, vector<int>, greater<int>> q(nums1.begin(), nums1.begin() + m);
        int i = 0, j = 0;
        while (!q.empty()) {
            if (j < n && q.top() > nums2[j]) nums1[i++] = nums2[j++];
            else {
                nums1[i++] = q.top();
                q.pop();
            }
        }
        while (j < n) nums1[i++] = nums2[j++];
    }
};