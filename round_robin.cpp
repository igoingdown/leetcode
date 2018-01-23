#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Scheduler {
private:
	vector<int*> servers;
	int i;
public:
	Scheduler(vector<int*> v) {
		servers = v;
		i = -1;
	}
	int* choose_server() {
		i = (i + 1) % servers.size();
		return servers[i];
	}
};


class WeightedScheduler{
private:
	vector<int*> servers;
	vector<int> weights;
	int i;
	int cw;
	int max_weight;
public:
	WeightedScheduler(vector<int*> s, vector<int> w) {
		servers = s;
		weights = w;
		i = -1;
		cw = 0;
		max_weight = 0;
		for (int weight : weights) max_weight = max(max_weight, weight);
	}
	// 使用cw记录当前请求应该分配给weight多大的server，
	// 将cw逐渐减小直到最后所有server在接收请求后权重都一样
	int* choose_server() {
		while(1) {
			i = (i + 1) % (servers.size());
			if (i == 0) {
				cw -= ngcd(servers.size() - 1);
				if (cw <= 0) {
					cw = max_weight;
					if (cw == 0) return NULL;
				}
			}
			if (weights[i] >= cw) return servers[i];
		}
	}

	int gcd(int a, int b) {
		if (a < b) swap(a, b);
		while (b) {
			a %= b;
			swap(a, b);
		}
		return a;
	}
	int ngcd(int n) {
		if (n == 0) return weights[n];
		return gcd(weights[n], ngcd(n - 1));
	}

	int lcm(int a, int b) {
		return a * b / gcd(a, b);
	}

	int nlcm(int n) {
		if (n == 0) return weights[n];
		return lcm(weights[n], nlcm(n - 1));
	}
};


int main() {
	vector<int*> v(5, NULL);
	for (int i = 0; i < 5; i++) v[i] = new int(i);
	Scheduler s(v);
	for (int i = 0; i < 10; i++) cout << *(s.choose_server()) << " ";
	cout << endl;
	vector<int> w = {2, 1, 1, 2, 1};
	WeightedScheduler w_s(v, w);
	for (int i = 0; i < 40; i++) cout << *(w_s.choose_server()) << " ";
	cout << endl;
	return 0;
}


