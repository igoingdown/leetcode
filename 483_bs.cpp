class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = stoull(n);
        for (int i = 62; i >= 1; i--) {
            unsigned long long k = BS(num, i);
            if (k > 1) return to_string(k);
        }
        return "";
    }
    
    unsigned long long BS(unsigned long long num, int len) {
        unsigned long long low = 1, high = num, mid, tmp = num - 1, base = 1;
        int i = 0;
        while (low < high) {
            mid = low + ((high - low) >> 1);
            tmp = num, base = 1, i = 0;
            bool overflowed = false;
            while (i <= len && tmp >= base) {
                tmp -= base;
                if (ULLONG_MAX / mid < base || (ULLONG_MAX / mid == base && ULLONG_MAX % mid > 0)) overflowed = true;
                base *= mid;
                i++;
                if (overflowed) break;
            }
            if (tmp == 0 && i == len + 1) return mid;
            else if (i > len) low = mid + 1;
            else high = mid;
           }
        return i > len && tmp == 0 ? low : 0;
    }
};