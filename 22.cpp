class Solution {
private:
    void addPar(vector<string>& res, string can, int n, int m) {
        if (n == 0 && m == 0) {
            res.push_back(can);
            return;
        }
        if (m > 0) {
            addPar(res, can + ")", n, m - 1);
        }
        if (n > 0) {
            addPar(res, can + "(", n - 1, m + 1);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addPar(res, "", n, 0);
        return res;
    }
};
