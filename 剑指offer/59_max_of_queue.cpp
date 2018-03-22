#include <iostream>
#include <sstream>
#include <queue>
#include <cassert>

using namespace std;

template <typename T> class QueueWithMax{
public:
	void push_back(T num) {
		while (!maximums.empty() && num > maximums.back()) maximums.pop_back();
		maximums.push_back(num); q.push_back(num);
	}

	void pop_front() {
		assert(!q.empty() && !maximums.empty());
		if (q.front() == maximums.front()) maximums.pop_front();
		q.pop_front();
	}

	pair<T, T> front() {
		assert(!q.empty() && !maximums.empty());
		return {q.front(), maximums.front()};
	}

	bool empty() {
		return q.empty() && maximums.empty();
	}

	pair<T, T> back() {
		assert(!q.empty() && !maximums.empty());
		return {q.back(), maximums.back()};
	}

private:
	deque<T> q, maximums;
};

int main(int argc, char const *argv[])
{
	/* code */
	QueueWithMax<int> q;
	int x;
	while (cin >> x) {
		q.push_back(x); auto p = q.back();
		cout << "[" << p.first << " " << p.second << "]" << endl;
	}
	while (!q.empty()) {
		auto p = q.front();
		cout << "[" << p.first << " " << p.second << "]" << endl;
		q.pop_front(); 
	}
	return 0;
}


