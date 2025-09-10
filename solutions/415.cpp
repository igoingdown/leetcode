class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i = 0, j = 0, c = 0;
        int s1 = num1.size(), s2 = num2.size();
        for (;i < num1.size() && j < num2.size(); i++, j++) {
            int sum = num1[s1 - 1 - i] - '0' + num2[s2 - 1 - j] - '0' + c;
            res = to_string(sum % 10) + res;
            c = sum / 10;
        }
        if (i < num1.size()) {
            for (; i < num1.size(); i++) {
                int sum = num1[s1 - 1 - i] - '0' + c;
                res = to_string(sum % 10) + res;
                c = sum / 10;
            }
            
        }
        
        if (j < num2.size()) {
            for (; j < num2.size(); j++) {
                int sum = num2[s2 - 1 - j] - '0' + c;
                res = to_string(sum % 10) + res;
                c = sum / 10;
            }
        }
        if (c) {
            res = to_string(c) + res;
        }
        return res;
    }
};
