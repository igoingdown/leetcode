class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double low = 0, high = 1e8;
        for (int rep = 0; rep < 80; rep++) {
            double mid = low + (high - low) / 2;
            int need = 0;
            for (int i = 1; i < stations.size(); i++) need += (int)((stations[i] - stations[i - 1]) / mid);
            if (need > K) low = mid;
            else high = mid;
        }
        return high;
    }
};