class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        for (int i = 0; i < n; i++) {
            for(int s = res.size() - 1; s >= 0; s--) res.push_back(res[s] | (1 << i));
        }
        return res;
    }
};