class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        set<char> s(J.begin(), J.end());
        for (char c : S) if (s.find(c) != s.end()) res++;
        return res;
    }
};