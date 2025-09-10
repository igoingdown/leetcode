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
        return a.end < b.end;
    }
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n < 2) return 0;
        sort(intervals.begin(), intervals.end(), myCompare);
        int res = 1, pos = intervals[0].end;
        for (auto i : intervals) {
            if (i.start >= pos) {
                res++;
                pos = i.end;
            }
        }
        return n - res;
    }
};