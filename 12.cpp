class Solution {
public:
    string intToRoman(int num) {
        vector<string> m = {"", "M", "MM", "MMM"};
        vector<string> c = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> x = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> i = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return m[num / 1000] + c[num % 1000 / 100] + x[num % 100 / 10] + i[num % 10];
    }
};
