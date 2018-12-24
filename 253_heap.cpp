#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval(int b, int e): start(b), end(e){}
};

int rooms(vector<Interval> & intervals);

int main(int argc, char const *argv[])
{
	/* code */
	vector<Interval> intervals = {Interval(0, 30),Interval(5, 10), Interval(15, 20)};
	cout << rooms(intervals) << endl;
	return 0;
}

int rooms(vector<Interval> & intervals) {
	priority_queue<int, vector<int>, greater<int>> q;
	sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {return a.start < b.start;});
	for (const Interval & interval : intervals) {
		if (!q.empty() && q.top() <= interval.start) q.pop();
		q.push(interval.end);
	}
	return q.size();
}