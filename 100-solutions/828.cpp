class Solution {
public:
    int uniqueLetterString(string S) {
        // 计数字符串所有合法子串中，只出现一次的字符个数之和
        // 思想是：对于任意字符i，计算其为unique字符的子串个数，即向左、右两侧拓宽边界l和r，子串个数为(i - l) * (r - i)。
        long long res = 0, n = S.size(), mod = 1000000007;
        for (int i = 0; i < n; i++) {
            long long l = i - 1, r = i + 1;
            while (l >= 0 && S[l] != S[i]) --l;
            while (r < n && S[r] != S[i]) ++r;
            res += (i - l) * (r - i);
            res %= mod;
        }
        return res;
    }
};