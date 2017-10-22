class Solution {
private:
    void max_heapify(vector<pair<int, int> >& s, int b, int e) {
        int cur = b, child = 2 * b + 1;
        while (child < e) {
            if (child + 1 < e && s[child].first + s[child].second > s[child + 1].first + s[child + 1].second) {
                child++;
            }
            if (s[cur].first + s[cur].second > s[child].first + s[child].second) {
                swap(s[cur], s[child]);
                cur = child;
                child = 2 * child + 1;
            } else {
                break;
            }
        }
    }
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int s1 = nums1.size(), s2 = nums2.size();
        vector<pair<int, int> > s;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                s.push_back(make_pair(n1, n2));
            }
        }
        int s_size = s.size();
        for (int i = s_size / 2 - 1; i >= 0; i--) {
            max_heapify(s, i, s_size);
        }
        k = min(k, s_size);
        vector<pair<int, int>> res;
        for (int i = s_size - 1; i >= s_size - k; i--) {
            swap(s[i], s[0]);
            res.push_back(s[i]);
            max_heapify(s, 0, i);
        }
        return res;
    }
};