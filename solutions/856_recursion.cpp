class Solution {
public:
    int scoreOfParentheses(string S) {
        if (S == "()") return 1;
        stack<char> s;
        s.push(S[0]);
        int i = 1;
        while (i < S.size()) {
            if (S[i] == '(') s.push(S[i]);
            else s.pop();
            if (s.empty()) break;
            i++;
        }
        string s1 = (i - 1 > 0 ? S.substr(1, i - 1) : ""), s2 = (i + 1 == S.size() ? "" : S.substr(i + 1));
        return (s1 == "" ? 1 : 2 * scoreOfParentheses(s1)) + (s2 == "" ? 0 : scoreOfParentheses(s2));
    }
};