#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void handle(vector<int> &res, queue<int> &q) {
	int head = q.front();
	q.pop();
	res.push_back(head);
	int n = res.size(), i = n - 1;
	while (i > 0 && res[i - 1] != head) i--;
	if (i > 0) {
		while (n >= i) {
			q.push(res[n - 1]);
			res.pop_back();
			n--;
		}
	}
}

bool vs(vector<int> &ha, vector<int> &heng) {
	queue<int> haq, hengq;
	vector<int> res;
	res.reserve(100);
	for (int n : ha) {
		haq.push(n);
	}
	for (int n : heng) {
		hengq.push(n);
	}
	while (!hengq.empty() && !haq.empty()) {
		handle(res, haq);
		if (haq.empty()) return false;
		handle(res, hengq);
		if (hengq.empty()) return true;
	}
	return true;
}

int main() {
	vector<int> a = {2,4,1,2,5,6};
	vector<int> b = {3,1,3,5,6,4};
	cout << vs(a, b) << endl;
}
