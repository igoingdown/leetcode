/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {return a.start < b.start;});
        res.push_back(intervals[0]);
        for (auto i : intervals) {
            if (i.start <= res.back().end) res.back().end = max(i.end, res.back().end);
            else res.push_back(i);
        }
        return res;
    }
};