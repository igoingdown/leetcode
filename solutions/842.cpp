class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        return dfs(0, S, res) ? res : vector<int>();
    }
    
    bool dfs(int start, const string &S, vector<int> &res) {
        if (start >= S.size()) return res.size() > 2;
        if (S[start] == '0') {
            if (res.size() < 2 || 0 - res[res.size() - 1] == res[res.size() - 2]) {
                res.push_back(0);
                if (dfs(start + 1, S, res)) return true;
                res.pop_back();
            }
        } else {
            int max_i = to_string(INT_MAX).size();
            for (int i = 1; i < max_i || (i == max_i && S.substr(start, i) <= to_string(INT_MAX)); i++) {
                int cur = stoi(S.substr(start, i));
                int res_size = res.size();
                if (res_size < 2 || cur - res[res_size - 1] == res[res_size - 2]) {
                    res.push_back(cur);
                    if (dfs(start + i, S, res)) return true;
                    res.pop_back();
                }
                if (res_size > 1 && cur - res[res_size - 1] > res[res_size - 2]) break;
            }
        }
        return false;
    }
};
