class Solution {
public:
    string maskPII(string S) {
        auto dot_iter = find(S.begin(), S.end(), '.');
        auto at_iter = find(S.begin(), S.end(), '@');
        string res;
        if (dot_iter != S.end() && at_iter != S.end()) {
            string name1 = S.substr(0, at_iter - S.begin());
            string name2 = S.substr(at_iter - S.begin() + 1, dot_iter - at_iter - 1);
            string name3 = S.substr(dot_iter - S.begin() + 1);
            res += tolower(name1[0]);
            res += "*****";
            res += tolower(name1[name1.size() - 1]);
            res += "@";
            for (char c : name2) res += tolower(c);
            res += ".";
            for (char c : name3) res += tolower(c);
        } else {
            string num;
            for (char c : S) {
                if (isdigit(c)) num += c;
            }
            string tail = num.substr(num.size() - 4);
            string head;
            if (num.size() > 10) {
                head += "+";
                string contry_code(num.size() - 10, '*');
                head += contry_code;
                head += "-";
            }
            res = head + "***-***-" + tail;
        }
        return res;
    }
};