#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

vector<int> findRightInterval(vector<Interval>& intervals);

int main(int argc, char const *argv[]) {
  /* code */
  vector<Interval> v;
  v.push_back( Interval(1, 2) );
  v.push_back( Interval(2, 3) );
  v.push_back( Interval(0, 1) );
  v.push_back( Interval(3, 4) );
  vector<int> res = findRightInterval(v);
  for (auto i : res) {
    cout << i << endl;
  }
  return 0;
}

vector<int> findRightInterval(vector<Interval>& intervals) {
     vector<int> res;
     map<int, int> m;
     for (int i = 0; i < intervals.size(); i++) {
         m[intervals[i].start] = i;
     }
     for (auto interval: intervals) {
         auto itr = m.lower_bound(interval.end);
         if (itr == m.end()) {
             res.push_back(-1);
         } else {
             res.push_back(itr->second);
         }
     }
     return res;
 }
