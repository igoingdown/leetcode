#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <string>


using namespace std;

int mean_of_stream(istringstream &in);

int main() {
	string s = "1 2 5 10 3 19 10 ";
	istringstream in(s);
	cout << mean_of_stream(in) << endl;
	return 0;
}

int mean_of_stream(istringstream &in) {
	int a;
	priority_queue<int, vector<int>, less<int>> low;
	priority_queue<int, vector<int>, greater<int>> high;
	while (in >> a) {
		cout << "a: " << a << " ";
		if (!low.empty()) cout << "low : " << low.top() << " ";
		if (!high.empty()) cout << "high: " << high.top() << " ";
		cout << endl;
		if (low.size() == high.size()) {
			if (!high.empty() && a > high.top()) {
				low.push(high.top()); high.pop(); high.push(a);
			} else low.push(a);
		} else {
			if (!low.empty() && a < low.top()) {
				high.push(low.top()); low.pop(); low.push(a);
			} else high.push(a);
		}
		
	}
	return low.size() == high.size() ? ((low.top() + high.top()) >> 1 ) : low.top();
}


