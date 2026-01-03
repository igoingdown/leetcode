class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n);
        if (n == 0) return res;
        int i = 0, right = 0;
        while (right < n && S[right] != C) ++right;
        for (int i = 0; i < S.size(); i++) {
            if (right < n && i <= right) res[i] = right - i;
            else if (right >= S.size()) res[i] = 10001;
            else {
                for (right = i; right < n && S[right] != C; right++);
                res[i] = right < S.size() && right >= i ? right - i : 10001;
            }
        }
        int left = n - 1;
        while (left >= 0 && S[left] != C) --left;
        for (int i = n - 1; i >= 0; i--) {
            if (left >= 0 && left < i) res[i] = min(i - left, res[i]);
            else if (left >= i) {
                for (left = i - 1; left >= 0 && S[left] != C; left--);
                res[i] = left >= 0 ? min(i - left, res[i]) : res[i];
            }
        }
        return res;
    }
};