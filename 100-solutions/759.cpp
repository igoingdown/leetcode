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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
        vector<Interval> res(0);
        vector<Interval> intervals;
        for (auto v : avails) {
            for (auto i : v) intervals.push_back(i);
        }
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), myCompare);
        vector<Interval> c(1, intervals[0]);
        for (auto i : intervals) {
            if (i.start <= c.back().end) c.back().end = max(c.back().end, i.end);
            else c.push_back(i);
        }
        for (int i = 1; i < c.size(); i++) res.push_back(Interval(c[i - 1].end, c[i].start));
        return res;
    }
    static bool myCompare(Interval& a, Interval& b) {
        return a.start < b.start;
    }
};