class Solution {
private:
    static bool myCompare(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n < 2) return n;
        sort(points.begin(), points.end(), myCompare);
        int res = 1, arror_pos = points[0].second;
        for (auto p : points) {
            if (p.first <= arror_pos) continue;
            res++;
            arror_pos = p.second;
        }
        return res;
    }
};