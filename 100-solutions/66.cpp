class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1, n = digits.size(), s = 0;
        for (int i = n - 1; i >= 0; i--) {
            s = c + digits[i];
            digits[i] = s % 10;
            c = s / 10;
        }
        if (c > 0)  {
            digits.resize(n + 1, 0);
            for (int i = n; i > 0; i--) digits[i] = digits[i - 1];
            digits[0] = c;
        }        
        return digits;
    }
};