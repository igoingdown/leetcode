class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s = to_string(N);
        vector<int> digits(10);
        for (char c : s) digits[c - '0']++;
        string num;
        return combinations(digits, num, s.size());
    }

    bool combinations(vector<int> &digits, string &num, int maxSize) {
        if (num.size() == maxSize) {
            if (isPowerOf2(num)) return true;
        }
        for (int i = 0; i < 10; i++) {
            if (digits[i] > 0) {
                if (i == 0 && num.size() == 0) continue;
                digits[i]--;
                num += i + '0';
                if (combinations(digits, num, maxSize)) return true;
                digits[i]++;
                num.pop_back();
            }
        }
        return false;
    }

    bool isPowerOf2(const string& str) {
        bitset<64> bs(stol(str));
        return bs.count() == 1;
    }
};