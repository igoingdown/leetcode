class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W != 0) return false;
        int g = n / W;
        map<int, int> m;
        for (int i : hand) m[i]++;
        while (g--) {
            int b = m.begin()->first, e = b + W;
            for (int i = b; i < e; i++) {
                if (m.find(i) == m.end()) return false;
                m[i]--;
                if (m[i] == 0) m.erase(i);
            }
        }
        return true;
    }
};