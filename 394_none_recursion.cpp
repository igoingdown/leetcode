class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string res;
        int n = 0;
        for (char c : s) {
            if (isdigit(c)) {
                n = n * 10 + c - '0';
            } else if (isalpha(c)) {
                res += c;
            } else if (c == '[') {
                chars.push(res);
                nums.push(n);
                n = 0;
                res = "";
            } else if (c == ']') {
                string tmp;
                while (nums.top()--) {
                    tmp += res;
                }
                res = chars.top() + tmp;
                chars.pop();
                nums.pop();
            }
        }
        return res;
    }
};