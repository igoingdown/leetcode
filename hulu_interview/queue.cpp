#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class MyQueue
{
private:
	stack<int> s1, s2;
public:
	MyQueue(){}
	int pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top()); s1.pop();
			}
		}
		int res = s2.top(); s2.pop();
		return res;
	}
	void push(int x) {
		s1.push(x);
	}
	~MyQueue(){}
};


class MyDeque
{
private:
	stack<int> s1, s2;
public:
	MyDeque(){}
	
	void push_front(int x) {
		s1.push(x);
	}
	
	void push_back(int x) {
		s2.push(x);
	} 
	
	int pop_front() {
		if (s1.empty()) {
			while(!s2.empty()) {
				s1.push(s2.top()); s2.pop();
			}
		}
		int res = s1.top(); s1.pop();
		return res;
	}

	int pop_back(){
		if (s2.empty()) {
			while(!s1.empty()) {
				s2.push(s1.top()); s1.pop();
			}
		}
		int res = s2.top(); s2.pop();
		return res;
	}

	int size() {
		return s1.size() + s2.size();
	}

	bool empty() {
		return this->size() == 0;
	}
	~MyDeque(){}
	
};

vector<int> maxValInWindow(vector<int> &v, int k);

int main() {
	MyQueue q;
	q.push(2);
	q.push(3);
	cout << q.pop() << endl;
	q.push(4);
	cout << q.pop() << endl;
	cout << q.pop() << endl;

	MyDeque dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	cout << dq.size() << endl;
	cout << dq.pop_front() << endl;
	cout << dq.pop_back() << endl;
	vector<int> v = {4,3,5,4,3,3,6,7};
	for (auto i : maxValInWindow(v, 3)) cout << i << "\t";
	cout << endl;
}

vector<int> maxValInWindow(vector<int> &v, int k) {
	MyDeque q;
	vector<int> res;
	for (int i = 0; i < v.size(); i++) {
		while (!q.empty()) {
			int tmp = q.pop_back();
			if (v[tmp] > v[i]) {
				q.push_back(tmp); break;
			}
		}
		q.push_back(i);
		int tmp = q.empty() ? i - k : q.pop_front();
		if (tmp != i - k) q.push_front(tmp);
		if (i >= k - 1) {
			tmp = q.pop_front(); res.push_back(v[tmp]); q.push_front(tmp);
		}
	}
	return res;

}

