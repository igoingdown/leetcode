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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {return a.start < b.start;});
        vector<Interval> res(1, intervals[0]);
        for (auto i : intervals) {
            if (i.start <= res.back().end) res.back().end = max(i.end, res.back().end);
            else res.push_back(i);
        }
        return res;
    }
};