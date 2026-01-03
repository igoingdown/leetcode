class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> v_2(n, 0), v_1(n, 1), v(n, 0), *p_2 = &v_2, *p_1 = &v_1, *p = &v;
        for (int i = 2; i < n + 1; i++) {
            for (int j = 0; j < n - i + 1; j++) {
                p->at(j) = s[j] == s[j + i - 1] ? 2 + p_2->at(j + 1) : max(p_1->at(j), p_1->at(j + 1));
            }
            swap(p_2, p_1);
            swap(p_1, p);
        }
        return p_1->at(0);
    }
};