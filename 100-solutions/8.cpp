class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, i = 0, res = 0;
        for (; str[i] == ' '; i++);
        if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
            if (str[i] == '-') sign = -1;
            i++;
        }
        for (; i < str.size(); i++) {
            if (isdigit(str[i])) {
                if ((res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] >= '0' + INT_MAX % 10)) && sign > 0) return INT_MAX;
                else if ((res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] > '0' + INT_MAX % 10)) && sign < 0) return INT_MIN;
                else res = res * 10 + (str[i] - '0');
            } else return res * sign;
        }
        return res * sign;
    }
};