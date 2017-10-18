class Solution {
private:
    unordered_map<string, int> m;
    void max_heapify(vector<string>& s, int b, int e) {
        int cur = b, child = 2 * b + 1;
        while (child < e) {
            if (child + 1 < e && (m[s[child]] < m[s[child + 1]] || (m[s[child]] == m[s[child + 1]] && s[child] > s[child + 1]))){
                child++;
            }
            if (m[s[cur]] < m[s[child]] || (m[s[child]] == m[s[cur]] && s[cur] > s[child])) {
                swap(s[cur], s[child]);
                cur = child;
                child = child * 2 + 1;
            } else {
                break;
            }
        }
    }
                
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (auto word : words) {
            m[word]++;
        }
        vector<string> v;
        for (auto p : m) {
            v.push_back(p.first);
        }
        int s = v.size();
        for (int i = s / 2 - 1; i >= 0; i--) {
            max_heapify(v, i, s);
        }
        vector<string> res;
        for (int i = s - 1; i >= s - k; i--) {
            swap(v[i], v[0]);
            res.push_back(v[i]);
            max_heapify(v, 0, i);
        }
        return res;
    }
};