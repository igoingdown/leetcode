class Solution {
private:
    int get_count(int x) {
        int c = 0;
        for (int i = 0; i < 26; i++) {
            c += ((x >> i) & 1);
        }
        return c;
    }
public:
    int maxProduct(vector<string>& words) {
        map<string, pair<int, int>> m;
        for (string word : words) {
            if (m.find(word) == m.end()) {
                int e = 0;
                for (char c: word) {
                    e |= 1 << (c - 'a');
                }
                m[word] = make_pair(e, get_count(e));
            }
        }
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                auto p1 = m[words[i]], p2 = m[words[j]];
                int s1 = words[i].size(), s2 = words[j].size();
                if (get_count(p1.first ^ p2.first) == p1.second + p2.second) {
                    res = max(res, s1 * s2);
                }
            }
        }
        return res;
    }
};