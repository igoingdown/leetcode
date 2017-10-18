class Solution {
private:
    unordered_map<int, int> m;
    void max_heapify(vector<int>& s, int b, int e) {
        int cur = b, child = 2 * b + 1;
        while (child < e) {
            if (child + 1 < e && m[s[child]] < m[s[child + 1]]) {
                child++;
            }
            if (m[s[cur]] < m[s[child]]) {
                swap(s[cur], s[child]);
                cur = child;
                child = child * 2 + 1;
            } else {
                break;
            }
        }
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int n : nums) {
            m[n]++;
        }
        vector<int> s;
        for (auto p : m) {
            s.push_back(p.first);
        }
        int l = s.size();
        vector<int> res;
        for (int i = l / 2; i >= 0; i--) {
            max_heapify(s, i, l);
        }
        for (int i = l - 1; i >= l - k; i--) {
            swap(s[0], s[i]);
            res.push_back(s[i]);
            max_heapify(s, 0, i);
        }
        return res;
    }
};