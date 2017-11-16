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
        int n = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
        vector<Interval> res(1, intervals[0]);
        for (Interval i : intervals) {
            if (res.back().end < i.start) {
                res.push_back(i);
            } else {
                res.back().end = max(res.back().end, i.end);
            }
        }
        return res;
    }
};