#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> global_base;
class MyComparison {
public:
	bool operator() (vector<int> &vi, vector<int> &vj) {
		long long prod_i = 1, prod_j = 1;
		for (int k = 0; k < global_base.size(); k++) {
			prod_i *= pow(global_base[k], vi[k]); prod_j *= pow(global_base[k], vj[k]);
		}
		return prod_i > prod_j;
	}
};


vector<int> first_n_nums_pow(vector<int> &base, int k);

int main() {
	vector<int> base = {2, 3, 5, 7};
	int k = 5000;
	for (int i : first_n_nums_pow(base, k)) cout << i << " ";
	cout << endl;
	return 0;
}

/*
定义了一种数，质因子只有2,3,5,7。写个程序找到前k个这个数
比如, 1, 2, 3, 4, 5, 6, 8, 9, 10这些都是
建一个堆，堆中每个元素为vector，记录base vector中各数的指数，初始化堆中只有一个元素，所有指数均为0。
每次出堆，先检查当前值是否重复，不重复则加入res, 并把每个指数分别加1之后加入堆中。
这种方式不太好的地方在于当k很大时，堆中有大量用不到的元素。
当k取5911时结果超出了int的范围。
*/


vector<int> first_n_nums_pow(vector<int> &base, int k) {
	global_base = base;
	vector<int> res;
	priority_queue<vector<int>, vector<vector<int>>, MyComparison> heap;
	heap.push(vector<int> (base.size(), 0));
	while (res.size() <= k) {
		auto v = heap.top(); heap.pop();
		int cur = 1;
		for (int i = 0; i < base.size(); i++) cur *= pow(base[i], v[i]);
		if (res.size() == 0 ||(res.size() > 0 && res.back() != cur)) {
			res.push_back(cur);
			for (int i = 0; i < base.size(); i++) {
				v[i]++; heap.push(v); v[i]--;
			}
		}
	}
	return res;
}












