class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s,t;
        for (char c : S) {
            if (c == '#' && !s.empty()) s.pop();
            if (c != '#') s.push(c);
        }
        for (char c: T) {
            if (c == '#' && !t.empty()) t.pop();
            if (c != '#') t.push(c);
        }
        return s == t;
    }
};