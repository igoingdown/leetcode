#include <iostream>
#include <queue>

using namespace std;

string decode(string qq) {

	queue<char> q;
	for (char c : qq) {
		q.push(c);
	}
	string s;
	s.reserve(qq.size());
	while (!q.empty()) {
		s.push_back(q.front());
		q.pop();
		if (!q.empty()) {
			q.push(q.front());
			q.pop();
		}
	} 
	return s;
}

int main() {

	cout << decode("631758924") << endl;
}
