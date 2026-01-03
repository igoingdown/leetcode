class Solution {
private:
    void helper(vector<int>& res, int n) {
        if (n == 0) {
            res.push_back(0);
            return;
        }
        helper(res, n - 1);
        int s = res.size(), k = (1 << (n - 1) );
        for (int i = s - 1; i >= 0; i--) {
            res.push_back(k + res[i]);
        }
        return;
    }
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        helper(res, n);
        return res;
    }
};