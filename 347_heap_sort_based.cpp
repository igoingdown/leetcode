class Solution {
public:
    map<int, int> m;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int n : nums) m[n]++;
        vector<int> v, res;
        for (auto p : m) v.push_back(p.first);
        int n = v.size();
        for (int i = n / 2 - 1; i >= 0; i--) max_heapify(v, i, n);
        for (int i = n - 1; i >= 0 && k--; i--) {
            res.push_back(v[0]);
            swap(v[i], v[0]);
            max_heapify(v, 0, i);
        }
        return res;
    }
    void max_heapify(vector<int>& v, int b, int e) {
        int cur = b, child = 2 * b + 1;
        while (child < e) {
            if (child + 1 < e && m[v[child]] < m[v[child + 1]]) child++;
            if (m[v[cur]] < m[v[child]]) {
                swap(v[cur], v[child]);
                cur = child;
                child = child * 2 + 1;
            } else break;
        }
    }
};