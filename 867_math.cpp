typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;

#define REP(i, b, e) for (int i = b; i < e; i++)

class Solution {
public:
    int primePalindrome(int N) {
        if (N <= 2) return 2;
        if (N <= 3) return 3;
        if (N <= 5) return 5;
        if (N <= 7) return 7;
        REP(i, 0, 10000) {
            REP(t, -1, 10) {
                int p = mirror(i, t);
                if (p < N) continue;
                if (isParlindrome(p)) return p;
            }
        }
    }
    
    bool isParlindrome(ll x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
    
    int mirror(int x, int t) {
        string s = x > 0 ? to_string(x) : "";
        int ss = s.size();
        if (t >= 0) s += t + '0';
        for (int i = ss - 1; i >= 0; i--) s += s[i];
        return s.size() == 0 ? 0 : stoi(s);
    }
};