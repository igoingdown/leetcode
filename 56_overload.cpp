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
private:
    static bool myCompare(Interval a, Interval b) {
        return a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n < 2) return intervals;
        sort(intervals.begin(), intervals.end(), myCompare);
        vector<Interval> res(1, intervals[0]);
        for (Interval i : intervals) {
            if (i.start > res.back().end) {
                res.push_back(i);
            } else {
                res.back().end = max(res.back().end, i.end);
            }
        }
        return res;
    }
};