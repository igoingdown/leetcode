class Solution {
public:
    int calculate(string s) {
        int num = 0, res = 0, sign = 1;
        stack<int> signs;
        signs.push(1);
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            } else if (c == '+' || c == '-') {
                res += num * signs.top() * sign;
                sign = (c == '+' ? 1 : -1);
                num = 0;
            } else if (c == '(') {
                signs.push(signs.top() * sign);
                sign = 1;
            } else if (c == ')'){
                res += num * sign * signs.top();
                signs.pop();
                sign = 1;
                num = 0;
            }
        }
        if (num) res += num * sign * signs.top();
        return res;
    }
};