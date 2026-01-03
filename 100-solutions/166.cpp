class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int, int> div2Pos;
        string s;
        long long num = numerator;
        long long div = denominator;
        if (num * div < 0) {
            s += "-";
        }
        num = abs(num);
        div = abs(div);
        s += to_string(num / div);
        num %= div;
        if (num == 0) {
            return s;
        }
        s += ".";
        int pos = 1;
        bool flag = false;
        while (num) {
            num *= 10;
            if (div2Pos.find(num) != div2Pos.end()) {
                s += ")";
                flag = true;
                break;
            } else {
                div2Pos[num] = pos;
                s += to_string(num / div);
            }
            pos++;
            num %= div;
            cout << num << endl;
        }
        
        if (flag) {
            int p = s.find(".");
            s.insert(p + div2Pos[num], "(");
        }
        return s;
    }
};
