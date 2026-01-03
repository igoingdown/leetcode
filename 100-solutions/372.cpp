class Solution {
private:
    const int base = 1337;
    int powmod(int a, int k) {
        a %= base;
        int res = 1;
        for (int i = 0; i < k; i++) {
            res = res * a % base;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.size() < 1) {
            return 1;
        }
        int digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b) , 10) * powmod(a, digit) % base;
    }
};
