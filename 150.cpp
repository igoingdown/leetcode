class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string t : tokens) {
            if (t != "+" && t != "-" && t != "*" && t != "/") {
                s.push(stoi(t));
            } else {
                int e1 = s.top();
                s.pop();
                int e2 = s.top();
                s.pop();
                if (t == "+") {
                    s.push(e2 + e1);
                } else if (t == "-") {
                    s.push(e2 - e1);
                } else if (t == "*") {
                    s.push(e2 * e1);
                } else {
                    s.push(e2 / e1);
                }
            }
        }
        return s.empty() ? 0 : s.top();
    }
};