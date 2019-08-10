#include <iostream>
#include <vector>
#include <queue>


bool vs(vector<int> &ha, vector<int> &heng) {
	queue<int> haq, hengq;
	vector<int> res;
	res.reserve(100);
	for (int n : ha) {
		haq.push(n);
	}
	for (int n : heng) {
		hengq.push(n)
	}
	while (!hengq.empty() && !haq.empty()) {
		int head = haq.front();
		haq.pop();
		res.push_back(head);
		int n = res.size(), i = n - 1;
		while (i > 0 && res[i - 1] != head) i--;
		if (i > 0) {
			while (n >= i) {
				hap.push(res[n - 1]);
				res.pop_back();
				n--;
			}
		}
		if (haq.empty()) return false;
		head = hengq.front();
		hengq.pop();
		res.push_back(head);
		n = res.size(), i = n - 1;
		while (i > 0 && res[i - 1] != head) i--;
		if (i > 0) {
			while (n >= i) {
				hengq.push(res[n - 1]);
				res.pop_back();
				n--;
			}
		}
		if (hengq.empty()) return true;
	}
	return true;
}

int main() {

}
