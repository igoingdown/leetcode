class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int minR = 0;
        for (auto h: houses) {
            int curR = INT_MAX;
            auto high = lower_bound(heaters.begin(), heaters.end(), h);
            if (high != heaters.end()) {
                curR = *high - h;
            }
            if (high != heaters.begin()) {
                auto low = high - 1;
                curR = min(curR, h - *low);
            }
            minR = max(minR, curR);
        }
        return minR;
    }
};