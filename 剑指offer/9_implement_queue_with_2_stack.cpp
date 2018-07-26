#include <iostream>
#include <stack>
#include <exception>
#include <cassert>

using namespace std;


template <typename T> 
class MyQueue{
private:
	stack<T> s1, s2;
public:
	void push(const T &t) {
		s1.push(t);
	}

	T pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top()); s1.pop();
			}
		}
		assert(!s2.empty());
		T res = s2.top(); s2.pop();
		return res;
	}
};


int main() {
	MyQueue<int> q;
	q.push(1);
	q.push(2);
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	return 0;
}

